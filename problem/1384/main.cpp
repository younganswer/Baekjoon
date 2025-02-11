#include <iostream>
#include <string>
#include <vector>

#define MAX 20

int group = 0;
int n;
std::string arr[MAX][MAX];

int init() {
	std::cin >> n;
	if (n == 0) {
		return (-1);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> arr[i][j];
		}
	}
	return (0);
}

int solve() {
	std::vector<std::string> result;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == "N") {
				result.push_back(arr[(n + i - j) % n][0] + " was nasty about " + arr[i][0]);
			}
		}
	}

	if (group != 1) {
		std::cout << std::endl;
	}
	std::cout << "Group " << group << std::endl;
	if (result.empty()) {
		std::cout << "Nobody was nasty" << std::endl;
	} else {
		for (size_t i = 0; i < result.size(); i++) {
			std::cout << result[i] << std::endl;
		}
	}
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	while (++group) {
		if (init() != 0) {
			return (0);
		}

		if (solve() != 0) {
			return (-1);
		}
	}

	return (0);
}
