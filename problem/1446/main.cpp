#include <iostream>
#include <algorithm>

#define SUCCESS 0
#define FAILURE 0
#define MAX 12

typedef struct _Edge {
	int u;
	int v;
	int w;
}	Edge;

int N, D;
Edge edge[MAX];
int dp[10001];

int init() {
	std::cin >> N >> D;
	for (int i = 0; i < N; i++) {
		std::cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for (int i = 0; i <= 10000; i++) {
		dp[i] = i;
	}
	return (0);
}

int solve() {
	std::sort(edge, edge + N, [](Edge a, Edge b) {
		return (a.v < b.v);
	});

	for (int i = 0; i < N; i++) {
		if (dp[edge[i].v] <= dp[edge[i].u] + edge[i].w) {
			continue;
		}
		for (int j = edge[i].v; j <= D; j++) {
			dp[j] = dp[edge[i].u] + edge[i].w + j - edge[i].v;
		}
	}

	std::cout << dp[D] << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
