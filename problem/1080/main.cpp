#include <iostream>
#include <string>

#define MAX 50

int N, M;
std::string A[MAX], B[MAX];

int init() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}

	if (N < 3 || M < 3) {
		std::cout << -1 << std::endl;
		return (-1);
	}

	return (0);
}

int flip(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			A[i][j] = (A[i][j] == '0') ? '1' : '0';
		}
	}
	return (1);
}

int solve() {
	int cnt = 0;

	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 3; j++) {
			if (A[i][j] != B[i][j]) {
				cnt += flip(i, j);
			}
		}
	}

	for (int i = N - 2; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				std::cout << -1 << std::endl;
				return (0);
			}
		}
	}

	std::cout << cnt << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	if (init() != 0) {
		return (0);
	}

	if (solve() != 0) {
		return (0);
	}

	return (0);
}
