#include <iostream>
#include <string>

#define SUCCESS 0
#define FAILURE 0
#define MAX 100

int N, M;
std::string board[MAX];

int init() {
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> board[i];
	}
	return (0);
}

int flip(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] = (board[i][j] == '0') ? '1' : '0';
		}
	}
	return (1);
}

int solve() {
	int answer = 0;
	
	for (int i = N - 1; 0 <= i; i--) {
		for (int j = M - 1; 0 <= j; j--) {
			if (board[i][j] == '1') {
				answer += flip(i + 1, j + 1);
			}
		}
	}

	std::cout << answer << std::endl;
	
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
