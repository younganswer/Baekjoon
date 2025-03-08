#include <iostream>

#define SUCCESS 0
#define FAILURE 0
#define MAX 50

int N, C, W;
int wood[MAX];

int init() {
	std::cin >> N >> C >> W;
	for (int i = 0; i < N; i++) {
		std::cin >> wood[i];
	}
	return (0);
}

int solve() {
	long long answer = 0;

	for (int L = 1; L <= 10000; L++) {
		long long whole_profit = 0;
		
		for (int i = 0; i < N; i++) {
			int K = wood[i] / L;
			int cut = K - (wood[i] % L == 0);
			int profit = K * L * W - cut * C;

			if (profit <= 0) {
				continue;
			}

			whole_profit += profit;
		}

		answer = (answer < whole_profit) ? whole_profit : answer;
	}

	std::cout << answer << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
