#include <iostream>
#include <string>
#include <iomanip>

std::string month, day, year, hour, minute;
int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int parse() {
	if (month == "January") {
		month = "1";
	} else if (month == "February") {
		month = "2";
	} else if (month == "March") {
		month = "3";
	} else if (month == "April") {
		month = "4";
	} else if (month == "May") {
		month = "5";
	} else if (month == "June") {
		month = "6";
	} else if (month == "July") {
		month = "7";
	} else if (month == "August") {
		month = "8";
	} else if (month == "September") {
		month = "9";
	} else if (month == "October") {
		month = "10";
	} else if (month == "November") {
		month = "11";
	} else if (month == "December") {
		month = "12";
	} else {
		return (-1);
	}

	day = day.substr(0, day.length() - 1);
	minute = hour.substr(3, 2);
	hour = hour.substr(0, 2);

	return (0);
}

int init() {
	std::cin >> month >> day >> year >> hour;
	if (parse() != 0) {
		return (-1);
	}
	return (0);
}

int solve() {
	if (std::stoi(year) % 4 == 0 && (std::stoi(year) % 100 != 0 || std::stoi(year) % 400 == 0)) {
		days_in_month[2] = 29;
	}

	long double whole_time_in_minutes = 0;
	long double passed_time_in_minutes = 0;

	for (int i = 1; i <= 12; i++) {
		whole_time_in_minutes += days_in_month[i] * 24 * 60;
	}

	for (int i = 1; i < std::stoi(month); i++) {
		passed_time_in_minutes += days_in_month[i] * 24 * 60;
	}
	for (int i = 1; i < std::stoi(day); i++) {
		passed_time_in_minutes += 24 * 60;
	}
	passed_time_in_minutes += std::stoi(hour) * 60 + std::stoi(minute);

	std::cout << std::fixed << std::setprecision(9) << (passed_time_in_minutes / whole_time_in_minutes) * 100 << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	if (init() != 0) {
		return (-1);
	}

	if (solve() != 0) {
		return (-1);
	}

	return (0);
}
