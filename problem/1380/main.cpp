#include <iostream>
#include <string>

#define MAX 101

int			scenario = 0;
int			n;
std::string	name[MAX];
bool 		status[MAX];

int init() {
	std::cin >> n;
	if (n == 0) {
		return (-1);
	}
	for (int i = 1; i <= n; i++) {
		std::string first_name, last_name;
		std::cin >> first_name >> last_name;
		name[i] = first_name + " " + last_name;
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		int index;
		char c;
		std::cin >> index >> c;
		status[index] = !status[index];
	}
	return (0);
}

int solve() {
	for (int i = 1; i <= n; i++) {
		if (status[i]) {
			std::cout << scenario << ' ' << name[i] << std::endl;
			break;
		}
	}
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	while (++scenario) {
		if (init() != 0) {
			break;
		}
		if (solve() != 0) {
			return (-1);
		}
	}

	return (0);
}
