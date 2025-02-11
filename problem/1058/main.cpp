#include <iostream>
#include <string>
#include <queue>

#define MAX 50

int N;
std::string is_friend[MAX];
bool		visited[MAX];

int init() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> is_friend[i];
	}
	return (0);
}

int solve() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		std::queue<int> q;
		
		for (int j = 0; j < N; j++) {
			visited[j] = false;
		}
		visited[i] = true;

		for (int j = 0; j < N; j++) {
			if (is_friend[i][j] == 'Y') {
				q.push(j);
				visited[j] = true;
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int j = 0; j < N; j++) {
				if (is_friend[cur][j] == 'Y' && !visited[j]) {
					visited[j] = true;
				}
			}
		}

		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (visited[j]) {
				cnt++;
			}
		}

		answer = (answer < cnt) ? cnt : answer;
	}

	std::cout << (answer - 1) << std::endl;

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
