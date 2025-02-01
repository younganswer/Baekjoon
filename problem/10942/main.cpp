#include <iostream>
#include <vector>

#define MAX 2000

int numbers[MAX];
int N, M;
bool dp[MAX][MAX] = {false, };

bool init() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> numbers[i];
		dp[i][i] = true;
	}

	return (true);
}

bool solve() {
	if (2 <= N) {
		dp[N-2][N-1] = (numbers[N-2] == numbers[N-1]);
	}
	
	for (int i=N-3; 0<=i; i--) {
		dp[i][i+1] = (numbers[i] == numbers[i+1]);
		for (int j=i+2; j<N; j++) {
			dp[i][j] = dp[i+1][j-1] && (numbers[i] == numbers[j]);
		}
	}

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		std::cin >> S >> E;
		std::cout << dp[S-1][E-1] << '\n';
	}

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
