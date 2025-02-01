#include <iostream>

#define MAX 1000
#define INF 1e9

int N;
int costs[MAX][3];
int dp[MAX][3];

bool init() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
	}

	return (true);
}

bool solve() {
	int answer = INF;
	for (int i=0; i<3; i++) {
		dp[0][i] = costs[0][i];
		dp[0][(i+1)%3] = INF;
		dp[0][(i+2)%3] = INF;
		for (int j=1; j<N; j++) {
			dp[j][0] = std::min(dp[j-1][1], dp[j-1][2]) + costs[j][0];
			dp[j][1] = std::min(dp[j-1][0], dp[j-1][2]) + costs[j][1];
			dp[j][2] = std::min(dp[j-1][0], dp[j-1][1]) + costs[j][2];
		}
		answer = std::min(answer, std::min(dp[N-1][(i+1)%3], dp[N-1][(i+2)%3]));
	}
	std::cout << std::min(dp[N-1][0], std::min(dp[N-1][1], dp[N-1][2])) << '\n';

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
