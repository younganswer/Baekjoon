#include <iostream>
#include <string>
#include <algorithm>

std::string	word;

int init() {
	std::cin >> word;
	if (std::cin.fail()) {
		return (-1);
	}
	return (0);
}

int solve() {
	std::string result = "~";
	size_t len = word.length();

	for (size_t i = 1; i < len - 1; i++) {
		for (size_t j = i + 1; j < len; j++) {
			std::string a = word.substr(0, i);
			std::string b = word.substr(i, j - i);
			std::string c = word.substr(j, len - j);

			std::reverse(a.begin(), a.end());
			std::reverse(b.begin(), b.end());
			std::reverse(c.begin(), c.end());

			std::string temp = a + b + c;
			
			if (temp < result) {
				result = temp;
			}
		}
	}
	
	std::cout << result << std::endl;
	
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
