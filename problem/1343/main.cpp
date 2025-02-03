#include <iostream>
#include <string>

std::string board;

int init() {
	std::cin >> board;
	return (0);
}

int solve() {
	size_t idx = 0;

	while (idx < board.size()) {
		if (board[idx] == '.') {
			idx++;
			continue;
		}

		if (board[idx + 1] == '.') {
			std::cout << -1 << std::endl;
			return (0);
		}

		if (idx + 3 < board.size() && board[idx + 1] == 'X' && board[idx + 2] == 'X' && board[idx + 3] == 'X') {
			board[idx] = board[idx + 1] = board[idx + 2] = board[idx + 3] = 'A';
			idx += 4;
			continue;
		}

		if (idx + 1 == board.size()) {
			std::cout << -1 << std::endl;
			return (0);
		}

		board[idx] = board[idx + 1] = 'B';
		idx += 2;
	}

	std::cout << board << std::endl;

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
