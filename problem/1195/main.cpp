#include <iostream>
#include <algorithm>

#define SUCCESS 0
#define FAILURE 0
#define MAX 100

std::string gear[2];

int init() {
	for (int i = 0; i < 2; i++) {
		std::cin >> gear[i];
	}
	return (0);
}

int solve() {
	size_t ret = gear[0].size() + gear[1].size();
	
	for (int offset = -1 * gear[1].size(); offset < (int) gear[0].size(); offset++) {
		for (size_t i = std::max(0, offset); i < std::min(gear[0].size(), gear[1].size() + offset); i++) {
			if (gear[0][i] == '2' && gear[1][i - offset] == '2') {
				goto next;
			}
		}
		ret = std::min(ret, std::max(gear[0].size(), gear[1].size() + offset) - std::min(0, offset));
		next:;
	}

	std::cout << ret << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
