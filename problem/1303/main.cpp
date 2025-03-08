#include <iostream>
#include <string>
#include <queue>

#define SUCCESS 0
#define FAILURE 0
#define MAX 100

class Coordinate {
public:
	int x;
	int y;
};

int N, M;
std::string map[MAX];
bool visited[MAX][MAX];

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int init() {
	std::cin >> M >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> map[i];
	}
	return (0);
}

int solve() {
	std::queue<Coordinate> queue;
	int W = 0, B = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) {
				continue;
			}
			int cnt = 0;
			queue.push({ i, j });
			visited[i][j] = true;
			cnt++;
			while (!queue.empty()) {
				Coordinate current = queue.front();
				queue.pop();
				for (int k = 0; k < 4; k++) {
					int nx = current.x + dx[k];
					int ny = current.y + dy[k];
					if (nx < 0 || N <= nx || ny < 0 || M <= ny) {
						continue;
					}
					if (visited[nx][ny] || map[nx][ny] != map[current.x][current.y]) {
						continue;
					}
					queue.push({ nx, ny });
					visited[nx][ny] = true;
					cnt++;
				}
			}
			if (map[i][j] == 'W') {
				W += cnt * cnt;
			} else {
				B += cnt * cnt;
			}
		}
	}

	std::cout << W << " " << B << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
