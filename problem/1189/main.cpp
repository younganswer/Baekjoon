#include <iostream>

#define SUCCESS 0
#define FAILURE 0
#define MAX 5

int R, C, K;
std::string map[MAX];
bool visited[MAX][MAX];

int init() {
	std::cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		std::cin >> map[i];
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visited[i][j] = false;
		}
	}
	return (0);
}

int dfs(int r, int c, int k) {
	if (r == 0 && c == C - 1) {
		return (k == K);
	}

	int ret = 0;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 0 || R <= nr || nc < 0 || C <= nc) {
			continue;
		}
		if (visited[nr][nc] || map[nr][nc] == 'T') {
			continue;
		}
		visited[nr][nc] = true;
		ret += dfs(nr, nc, k + 1);
		visited[nr][nc] = false;
	}

	return (ret);
}

int solve() {
	visited[R - 1][0] = true;
	std::cout << dfs(R - 1, 0, 1) << std::endl;
	visited[R - 1][0] = false;
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
