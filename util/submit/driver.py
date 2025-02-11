import os
import sys
import time
import atexit
import requests
import subprocess

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service

driver = None

def wait_for_process(process, timeout=10):
	start_time = time.time()
	while time.time() - start_time < timeout:
		if process.poll() is None:
			print("Arc started successfully")
			return True
		time.sleep(0.5)
	print("Error: Failed to start Arc", file=sys.stderr)
	return False

def wait_for_arc(ip="127.0.0.1", port=9222, timeout=10):
	start_time = time.time()
	while time.time() - start_time < timeout:
		try:
			response = requests.get(f"http://{ip}:{port}/json/version", timeout=1)
			if response.status_code == 200:
				print("Successfully connected to Arc")
				return True
		except (ConnectionRefusedError, OSError, requests.RequestException):
			time.sleep(0.5)
	print("Error: Failed to connect to Arc", file=sys.stderr)
	return False

def start_arc(ip="127.0.0.1", port=9222):
	result = subprocess.run(["lsof", "-i", f":{port}"], capture_output=True, text=True)
	if result.stdout:
		if "Arc" in result.stdout:
			print(f"Arc is already running on port {port}", file=sys.stderr)
			return True
		print(f"Port {port} is already in use", file=sys.stderr)
		return False
	
	result = subprocess.run(["pgrep", "-f", "Arc.app"], capture_output=True, text=True)
	if result.stdout:
		subprocess.run(["pkill", "-f", "Arc.app"])
		while result.stdout:
			result = subprocess.run(["pgrep", "-f", "Arc.app"], capture_output=True, text=True)
			time.sleep(0.5)

	browser_path = os.getenv("BROWSER_PATH")
	if browser_path is None:
		print("Set the BROWSER_PATH environment variable", file=sys.stderr)
		sys.exit(1)

	user_data_dir = os.getenv("USER_DATA_DIR")
	if user_data_dir is None:
		print("Set the USER_DATA_DIR environment variable", file=sys.stderr)
		sys.exit(1)

	log_file = open("browser.log", "w")

	process = subprocess.Popen([
		browser_path,
		"--remote-debugging-port=9222",
		f"--user-data-dir={user_data_dir}",
	], stdout=log_file, stderr=log_file, preexec_fn=os.setpgrp)

	return (
		wait_for_process(process) and
		wait_for_arc(ip, port)
	)	

def initialize_driver(ip="127.0.0.1", port=9222):
	global driver

	if not start_arc(ip, port):
		sys.exit(1)

	executable_path = os.getenv("CHROMEDRIVER_PATH")
	if executable_path is None:
		print("Set the CHROMEDRIVER_PATH environment variable", file=sys.stderr)
		sys.exit(1)
	
	user_data_dir = os.getenv("USER_DATA_DIR")
	if user_data_dir is None:
		print("Set the USER_DATA_DIR environment variable", file=sys.stderr)
		sys.exit(1)
	
	service = Service(executable_path=executable_path)
	options = Options()
	options.add_argument(f"user-data-dir={user_data_dir}")
	options.add_experimental_option("debuggerAddress", f"{ip}:{port}")
	driver = webdriver.Chrome(service=service, options=options)
	atexit.register(lambda: driver.quit())

def get_driver():
	if driver is None:
		initialize_driver("127.0.0.1", 9222)
	return driver