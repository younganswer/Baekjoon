#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define N_MAX 101
#define M_MAX 5000
#define INF 1e9

std::vector< std::vector<int> > graph;
std::vector< std::vector<int> > kevin_bacon;

int N, M;

bool init(void) {
	std::cin >> N >> M;
	
	if (std::cin.fail() || N < 1 || N_MAX < N || M < 1 || M_MAX < M) {
		return (false);
	}

	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		if (std::cin.fail() || a < 1 || N < a || b < 1 || N < b) {
			return (false);
		}
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	kevin_bacon.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		kevin_bacon[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			kevin_bacon[i][j] = INF;
		}
	}

	return (true);
}

bool bfs(int start) {
	std::queue<int> q;
	q.push(start);
	kevin_bacon[start][start] = 0;

	while (q.empty() == false) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (kevin_bacon[start][next] == INF) {
				kevin_bacon[start][next] = kevin_bacon[start][current] + 1;
				q.push(next);
			}
		}
	}

	return (true);
}

int main(void) {
	if (init() == false) {
		std::cout << "INPUT ERROR!" << std::endl;
		return (0);
	}

	for (int i = 1; i <= N; i++) {
		bfs(i);
	}

	int dist = INF;
	int node = 0;

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += kevin_bacon[i][j];
		}
		if (dist > sum) {
			dist = sum;
			node = i;
		}
	}

	std::cout << node << std::endl;
	
	return (0);
}