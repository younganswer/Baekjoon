#include <iostream>
#include <vector>

#define SUCCESS 0
#define FAILURE 0
#define MAX 10000

int N, M;
std::vector<int> graph[MAX + 1];

int init() {
	std::cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[b].push_back(a);
	}
	
	return (0);
}

int bfs(int start) {
	int ret = 1;
	std::vector<bool> visited(MAX + 1, false);
	std::vector<int> queue;

	visited[start] = true;
	queue.push_back(start);
	while (!queue.empty()) {
		int cur = queue.back();
		queue.pop_back();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (visited[next]) {
				continue;
			}
			visited[next] = true;
			queue.push_back(next);
			ret++;
		}
	}

	return (ret);
}

int solve() {
	std::vector<int> answer;
	int max = 0;

	for (int i = 1; i <= N; i++) {
		int count = bfs(i);
		if (max < count) {
			max = count;
			answer.clear();
			answer.push_back(i);
		} else if (max == count) {
			answer.push_back(i);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		std::cout << answer[i] << " ";
	}
	std::cout << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
