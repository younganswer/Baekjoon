#include <iostream>
#include <queue>

#define MAX 600

using namespace std;

int		r, c;
int		N, M;
int		board[MAX][MAX];
bool	visited[MAX][MAX];

bool	init(void);
int		solve(void);

int	main(void) {
	int	answer;

	if (init() == false) {
		cout << "Fail to init" << endl;
		return (1);
	}
	answer = solve();
	if (answer == 0) {
		cout << "TT" << endl;
	}
	else {
		cout << answer << endl;
	}
	return (0);
} // end of main

bool	init(void) {
	cin >> N >> M;

	if (N < 1 || MAX < N || M < 1 || MAX < M) {
		return (false);
	}

	for (int i=0; i<N; i++) {
		string	row;

		cin >> row;
		for (int j=0; j<M; j++) {
			board[i][j] = row[j];
			if (board[i][j] == 'I') {
				r = i;
				c = j;
			}
		}
	}
	return (true);
}

int	solve(void) {
	int						ret = 0;
	int						dr[4] = {-1, 0, 1, 0};
	int						dc[4] = {0, 1, 0, -1};
	queue<pair<int, int> >	q;

	q.push(make_pair(r, c));
	visited[r][c] = true;
	while (q.empty() == false) {
		pair<int, int>	cur = q.front();

		q.pop();
		for (int i=0; i<4; i++) {
			int	nr = cur.first + dr[i];
			int	nc = cur.second + dc[i];

			if (nr < 0 || N <= nr || nc < 0 || M <= nc) {
				continue ;
			}
			if (visited[nr][nc] == true) {
				continue ;
			}
			if (board[nr][nc] == 'X') {
				continue ;
			}
			if (board[nr][nc] == 'P') {
				ret++;
			}
			q.push(make_pair(nr, nc));
			visited[nr][nc] = true;
		}
	}
	return (ret);
}