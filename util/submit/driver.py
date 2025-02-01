import time
import socket
import atexit
import requests
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service

driver = None

def wait_for_arc(ip="127.0.0.1", port=9222, timeout=10):
	start_time = time.time()
	while time.time() - start_time < timeout:
		try:
			with socket.create_connection((ip, port), timeout=1):
				response = requests.get(f"http://{ip}:{port}/json/version", timeout=1)
				if response.status_code == 200:
					return True
		except (ConnectionRefusedError, OSError, requests.RequestException):
			time.sleep(0.5)
	return False

def initialize_driver(ip="127.0.0.1", port=9222):
	global driver

	if not wait_for_arc(ip, port):
		print("Failed to connect to Arc", file=sys.stderr)
		sys.exit(1)

	service = Service(executable_path="/usr/local/bin/chromedriver")
	options = Options()
	options.add_experimental_option("debuggerAddress", f"{ip}:{port}")
	driver = webdriver.Chrome(service=service, options=options)
	atexit.register(lambda: driver.quit())

def get_driver():
	global driver
	if driver is None:
		initialize_driver("127.0.0.1", 9222)
	return driver