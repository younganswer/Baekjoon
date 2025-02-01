import sys
import re
import requests
from driver import get_driver
from login import login

from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support import expected_conditions as EC

def open_submit_page(driver, url):
	original_window = driver.window_handles
	try:
		driver.execute_script(f"window.open('{url}')")
		WebDriverWait(driver, 10).until(
			lambda d: len(d.window_handles) > 1
		)
	except TimeoutException:
		print("Failed to open the submit page", file=sys.stderr)
		sys.exit(1)
	new_window = [window for window in driver.window_handles if window not in original_window][0]
	driver.switch_to.window(new_window)

	if driver.current_url != url:
		login()
	
def select_language(driver, language="C++17"):
	try:
		dropdown = WebDriverWait(driver, 10).until(
			lambda d: d.find_element(By.NAME, "language")
		)
	except TimeoutException:
		print("Failed to find the language select", file=sys.stderr)
		sys.exit(1)
	
	driver.execute_script("""
		var select = arguments[0];
		for (var i = 0; i < select.options.length; i++) {
			if (select.options[i].text === arguments[1]) {
				select.selectedIndex = i;
				select.dispatchEvent(new Event("change"));
				break;
			}
		}
		$(select).trigger("chosen:updated");
	""", dropdown, language)

def select_visibility(driver, visibility="code_open_accepted"):
	try:
		radio_button = WebDriverWait(driver, 10).until(
			lambda d: d.find_element(By.ID, visibility)
		)
	except TimeoutException:
		print("Failed to find the visibility select", file=sys.stderr)
		sys.exit(1)
	
	driver.execute_script("arguments[0].click()", radio_button)

def upload_source_code(driver, problem_id):
	try:
		with open(f"./{problem_id}/main.cpp", "r") as file:
			source_code = file.read()
		driver.execute_script("""
			var editor = document.querySelector(".CodeMirror").CodeMirror;
			editor.setValue(arguments[0]);
		""", source_code)
	except FileNotFoundError:
		print("Failed to find the source code file", file=sys.stderr)
		sys.exit(1)
	except TimeoutException:
		print("Failed to find the source code editor", file=sys.stderr)
		sys.exit(1)
	
def click_submit_button(driver):
	try:
		submit_button = WebDriverWait(driver, 10).until(
			lambda d: d.find_element(By.ID, "submit_button")
		)
	except TimeoutException:
		print("Failed to find the submit button", file=sys.stderr)
		sys.exit(1)
	
	submit_button.click()
	
def submit(problem_id):
	driver = get_driver()
	url = f"https://www.acmicpc.net/submit/{problem_id}"

	open_submit_page(driver, url)
	select_language(driver)
	select_visibility(driver)
	upload_source_code(driver, problem_id)
	click_submit_button(driver)
