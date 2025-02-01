#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000

std::vector< std::pair<int, int> > graph[(MAX) + 1] = {std::vector< std::pair<int, int> >(), };
bool visited[(MAX) + 1] = {false, };
int answer = 0;
int furthest = 0;
int vertices = 0;

int N, M;

bool init() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		graph[u].push_back(std::make_pair(v, w));
		graph[v].push_back(std::make_pair(u, w));
	}

	return (true);
}

struct Compare {
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return (b.second < a.second);
	}
};

bool solve() {
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, Compare > pq;

	pq.push(std::make_pair(1, 0));
	while (pq.empty() == false && vertices < N) {
		int node = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (visited[node] == true) {
			continue;
		}

		visited[node] = true;
		answer += cost;
		furthest = (furthest < cost) ? cost : furthest;
		vertices++;

		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i].first;
			int next_cost = graph[node][i].second;

			if (visited[next] == true) {
				continue;
			}

			pq.push(std::make_pair(next, next_cost));
		}
	}

	std::cout << answer - furthest << std::endl;

	return (true);
}

int main() {
	if (init() == false) {
		return (1);
	}
	if (solve() == false) {
		return (1);
	}
	return (0);
}