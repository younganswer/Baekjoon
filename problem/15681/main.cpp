#include <iostream>
#include <vector>

#define MAX 100000

int N, R, Q;

std::vector<int> graph[(MAX) + 1] = {std::vector<int>(), };
bool visited[(MAX) + 1] = {false, };
int dp[(MAX) + 1] = {0, };

bool init(void) {
	std::cin >> N >> R >> Q;
	//if (std::cin.fail() || N < 1 || MAX < N || R < 1 || N < R || Q < 1 || MAX < Q) {
	//	return (false);
	//}

	int u, v;
	for (int i = 0; i < N-1; i++) {
		std::cin >> u >> v;
		//if (std::cin.fail() || u < 1 || N < u || v < 1 || N < v) {
		//	return (false);
		//}
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	return (true);
}

int dfs(int node) {
	if (dp[node] != 0) {
		return (dp[node]);
	}

	int ret = 1;
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (visited[next] == true) {
			continue;
		}
		ret += dfs(next);
	}
	dp[node] = ret;

	return (ret);
}

bool solve() {
	dp[R] = dfs(R);

	int query;

	for (int i = 0; i < Q; i++) {
		std::cin >> query;
		//if (std::cin.fail() || query < 1 || N < query) {
		//	return (false);
		//}
		std::cout << dp[query] << '\n';
	}

	return (true);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	if (init() == false) {
		return (1);
	}

	if (solve() == false) {
		return (1);
	}

	return (0);
}