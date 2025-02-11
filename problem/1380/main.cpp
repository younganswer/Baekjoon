#include <iostream>
#include <string>

#define MAX 100

int			scenario = 0;
int			n;
std::string	name[MAX + 1];
bool		status[MAX + 1];

int init() {
	std::cin >> n;
	if (n == 0) {
		return (-1);
	}
	std::cin.ignore();
	
	for (int i = 1; i <= n; i++) {
		std::getline(std::cin, name[i]);
		status[i] = false;
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
		if (status[i] == true) {
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
