#include <iostream>

#define MAX 2147483647

int T, A, B;

int init() {
	std::cin >> A >> B;
	return (0);
}

int solve() {
	// A = A * 1 => A는 A + 1로 변환 가능
	// A = A * -1 * -1 => A는 A - 2로 변환 가능
	// 위 두 가지 경우를 합치면 A는 A - 1로 변환 가능
	// 즉 A는 모든 수로 변환 가능
	std::cout << "yes" << std::endl;
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	std::cin >> T;

	while (T--) {
		if (init() != 0) {
			return (-1);
		}

		if (solve() != 0) {
			return (-1);
		}
	}

	return (0);
}
