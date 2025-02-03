#include <iostream>

int ty, tm, td;
int dy, dm, dd;

int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int init() {
	std::cin >> ty >> tm >> td;
	std::cin >> dy >> dm >> dd;
	return (0);
}

int solve() {
	if (1000 < dy - ty) {
		std::cout << "gg" << std::endl;
		return (0);
	}
	if (1000 == dy - ty) {
		if (tm < dm) {
			std::cout << "gg" << std::endl;
			return (0);
		}
		if (tm == dm) {
			if (td <= dd) {
				std::cout << "gg" << std::endl;
				return (0);
			}
		}
	}

	int dday = 0;
	while (ty != dy || tm != dm || td != dd) {
		if (ty % 4 == 0 && (ty % 100 != 0 || ty % 400 == 0)) {
			days_in_month[2] = 29;
		} else {
			days_in_month[2] = 28;
		}
		dday++;
		td++;
		if (td > days_in_month[tm]) {
			td = 1;
			tm++;
			if (tm > 12) {
				tm = 1;
				ty++;
			}
		}
	}

	std::cout << "D-" << dday << std::endl;

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
