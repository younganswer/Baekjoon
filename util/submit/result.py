import time
import sys
from driver import get_driver
from bs4 import BeautifulSoup

def result(timeout=60, interval=1):
	driver = get_driver()
	end_time = time.time() + timeout
	
	while time.time() < end_time:
		page_source = driver.page_source
		soup = BeautifulSoup(page_source, "html.parser")
		result_cell = soup.select_one("#status-table tbody tr:first-child td.result span.result-text")
		if result_cell:
			result_text = result_cell.get_text(strip=True)
			if "채점" not in result_text and result_text != "기다리는 중":
				print(f"결과: {result_text}")
				return
		time.sleep(interval)
		driver.refresh()

	print("Failed to get the result within the timeout period", file=sys.stderr)
	sys.exit(1)