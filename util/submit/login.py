import os
import sys
from driver import get_driver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.action_chains import ActionChains

def login():
	driver = get_driver()

	try:
		WebDriverWait(driver, 10).until(
			EC.url_contains("https://www.acmicpc.net/login")
		)
	except TimeoutException:
		print("Failed to open the login page", file=sys.stderr)
		sys.exit(1)

	login_user_id = os.getenv("USER_ID")
	login_password = os.getenv("USER_PW")

	if login_user_id is None or login_password is None:
		print("사용자 ID와 비밀번호를 .env 파일에 설정해주세요.", file=sys.stderr)
		sys.exit(1)
	
	# 아이디/비밀번호 입력
	try:
		user_id_input = WebDriverWait(driver, 10).until(
			EC.presence_of_element_located((By.NAME, "login_user_id"))
		)
		password_input = WebDriverWait(driver, 10).until(
			EC.presence_of_element_located((By.NAME, "login_password"))
		)
	except:
		print("Failed to find the login form", file=sys.stderr)
		sys.exit(1)

	driver.execute_script("arguments[0].value = arguments[1]", user_id_input, login_user_id)
	driver.execute_script("arguments[0].value = arguments[1]", password_input, login_password)

	login_button = WebDriverWait(driver, 10).until(
		EC.presence_of_element_located((By.ID, "submit_button"))
	)
	login_button.click()
	
	try:
		WebDriverWait(driver, 10).until(
			EC.url_contains("https://www.acmicpc.net/submit")
		)
	except TimeoutException:
		print("Failed to login", file=sys.stderr)
		sys.exit(1)