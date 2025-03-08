#include <iostream>

#define SUCCESS 0
#define FAILURE 0
#define MAX 50

int N, S, M;
int V[MAX];
int volume[1001] = {0, };

int init() {
	std::cin >> N >> S >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> V[i];
	}
	return (0);
}

int solve() {
	volume[S] = 1;
	
	for (int i = 0; i < N; i++) {
		int temp[1001] = {0, };

		for (int j = 0; j <= M; j++) {
			if (volume[j] == 0) {
				continue;
			}

			if (j - V[i] >= 0) {
				temp[j - V[i]] = 1;
			}

			if (j + V[i] <= M) {
				temp[j + V[i]] = 1;
			}
		}

		for (int j = 0; j <= M; j++) {
			volume[j] = temp[j];
		}
	}

	for (int i = M; i >= 0; i--) {
		if (volume[i] == 1) {
			std::cout << i << std::endl;
			return (0);
		}
	}

	if (volume[0] == 0) {
		std::cout << -1 << std::endl;
		return (0);
	}

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
