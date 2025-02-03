#include <iostream>
#include <set>

#define MAX 1000

int N;
int table[MAX][MAX];

int init() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> table[i][j];
		}
	}
	return (0);
}

int solve() {
	int answer = 0;
	std::set<int> graph[N];

	for (int grade = 0; grade < 5; grade++) {
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (table[i][grade] == table[j][grade]) {
					graph[i].insert(j);
					graph[j].insert(i);
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (graph[answer].size() < graph[i].size()) {
			answer = i;
		}
	}

	std::cout << (answer + 1) << std::endl;

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
