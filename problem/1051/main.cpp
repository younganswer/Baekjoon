#include <iostream>
#include <algorithm>
#include <string>

#define MAX 50

int N, M;
int board[MAX][MAX];

int init() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::string line;
		std::cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j];
		}
	}
	return (0);
}

int solve() {
	int len = std::min(N, M) + 1;

	while (--len) {
		for (int i = 0; i + len < N; i++) {
			for (int j = 0; j + len < M; j++) {
				if (board[i][j] == board[i + len][j] && board[i][j] == board[i][j + len] && board[i][j] == board[i + len][j + len]) {
					std::cout << (len + 1) * (len + 1) << std::endl;
					return (0);
				}
			}
		}
	}

	std::cout << 1 << std::endl;

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
