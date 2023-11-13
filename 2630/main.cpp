#include <iostream>

#define MAX 128

using namespace std;

int		white=0, blue=0;

bool	init(int &N, int board[MAX][MAX]);
bool	solve(int board[MAX][MAX], int r, int c, int length);

int	main(void) {
	int	N;
	int board[MAX][MAX] = {{0, }, };

	if (init(N, board) == false) {
		cout << "Error: N is out of range." << endl;
		return (1);
	}
	if (solve(board, 0, 0, N) == false) {
		cout << "Error: solve() failed." << endl;
		return (1);
	}
	cout << white << endl;
	cout << blue << endl;
	return (0);
} // end of main

bool	init(int &N, int board[MAX][MAX]) {
	cin >> N;
	if (N < 1 || 128 < N) {
		return (false);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}
	return (true);
} // end of init

bool	solve(int board[MAX][MAX], int r, int c, int length) {
	int color = board[r][c];

	for (int i=0; i<length; i++) {
		for (int j=0; j<length; j++) {
			if (board[r+i][c+j] != color) {
				solve(board, r, c, length/2);
				solve(board, r, c+length/2, length/2);
				solve(board, r+length/2, c, length/2);
				solve(board, r+length/2, c+length/2, length/2);
				return (true);
			}
		}
	}
	if (color == 0) {
		white++;
	}
	else {
		blue++;
	}
	return (true);
}