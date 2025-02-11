#include <iostream>
#include <algorithm>

#define MAX 50

int N;
int time_to_wait[MAX];

int init() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int appointment, arrival;
		std::cin >> appointment >> arrival;
		time_to_wait[i] = appointment - arrival;
	}
	return (0);
}

int solve() {
	std::sort(time_to_wait, time_to_wait + N);

	std::cout << time_to_wait[N / 2] - time_to_wait[(N - 1) / 2] + 1 << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	if (init() != 0) {
		return (-1);
	}

	if (solve() != 0) {
		return (-1);
	}

	return (0);
}
