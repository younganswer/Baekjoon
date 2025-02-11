#include <iostream>
#include <algorithm>

#define MAX 50

int N, M;
int brand[MAX][2];
int package_min = 1000, piece_min = 1000;

int init() {
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> brand[i][0] >> brand[i][1];
		package_min = std::min(package_min, brand[i][0]);
		piece_min = std::min(piece_min, brand[i][1]);
	}
	return (0);
}

int solve() {
	if (piece_min * 6 < package_min) {
		std::cout << N * piece_min << std::endl;
	} else {
		std::cout << std::min((N / 6 + 1) * package_min, (N / 6) * package_min + (N % 6) * piece_min) << std::endl;
	}
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
