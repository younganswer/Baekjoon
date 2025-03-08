#include <iostream>

#define SUCCESS 0
#define FAILURE 0
#define MAX 100000

int N;
int dp[MAX] = {0, };

int init() {
	std::cin >> N;
	return (0);
}

int solve() {
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= N; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}
	std::cout << dp[N] << std::endl;
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
