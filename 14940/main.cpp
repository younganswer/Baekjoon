#include <iostream>
#include <queue>

#define MAX 1000

using namespace std;

int		r, c;
int 	N, M;
int		board[MAX][MAX] = {{0, }, };
int		answer[MAX][MAX] = {{0, }, };
bool	visited[MAX][MAX] = {{false, }, };

bool	init(void);
bool	solve(void);

int	main(void) {
	if (init() == false) {
		cout << "Fail to init" << endl;
		return (1);
	}
	if (solve() == false) {
		cout << "Fail to solve" << endl;
		return (1);
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	return (0);
} // end of main

bool	init(void) {
	cin >> N >> M;
	if (N < 2 || MAX < N || M < 2 || MAX < M) {
		return (false);
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				r = i;
				c = j;
			}
		}
	}
	return (true);
}

bool	solve(void) {
	queue<pair<int, int> >	q;
	int						dr[4] = {-1, 0, 1, 0};
	int						dc[4] = {0, 1, 0, -1};

	q.push(make_pair(r, c));
	answer[r][c] = 0;
	visited[r][c] = true;
	while(q.empty() == false) {
		pair<int, int>	cur = q.front();

		q.pop();
		for (int i=0; i<4; i++) {
			int	nr = cur.first + dr[i];
			int	nc = cur.second + dc[i];

			if (nr < 0 || N <= nr || nc < 0 || M <= nc) {
				continue;
			}
			if (board[nr][nc] == 0 || visited[nr][nc] == true) {
				continue;
			}
			answer[nr][nc] = answer[cur.first][cur.second] + 1;
			visited[nr][nc] = true;
			q.push(make_pair(nr, nc));
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (board[i][j] == 1 && visited[i][j] == false) {
				answer[i][j] = -1;
			}
		}
	}
	return (true);
}