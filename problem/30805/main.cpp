#include <iostream>
#include <vector>
#include <queue>

#define MAX 100

std::queue<int> A[(MAX) + 1];
std::queue<int> B[(MAX) + 1];
std::vector<int> answer;

int N, M;

bool init(void) {
	int num;
	
	std::cin >> N;
	for (int i=0; i<N; i++) {
		std::cin >> num;
		if (std::cin.fail() || num < 1 || MAX < num) {
			return (false);
		}
		A[num].push(i);
	}

	std::cin >> M;
	for (int i=0; i<M; i++) {
		std::cin >> num;
		if (std::cin.fail() || num < 1 || MAX < num) {
			return (false);
		}
		B[num].push(i);
	}

	return (true);
}

int main(void) {
	if (init() == false) {
		std::cout << "Invalid input" << std::endl;
		return (1);
	}

	int num=100, i=0, j=0;
	while (0 < num) {
		if (A[num].size() == 0 || B[num].size() == 0) {
			num--;
			continue;
		}
		while (A[num].front() < i) {
			A[num].pop();
			if (A[num].size() == 0) {
				break;
			}
		}
		while (B[num].front() < j) {
			B[num].pop();
			if (B[num].size() == 0) {
				break;
			}
		}
		if (A[num].size() == 0 || B[num].size() == 0) {
			num--;
			continue;
		}
		i = A[num].front();
		j = B[num].front();
		A[num].pop();
		B[num].pop();
		answer.push_back(num);
	}

	std::cout << answer.size() << std::endl;
	for (int i=0; i<answer.size(); i++) {
		std::cout << answer[i];
		if (i < answer.size() - 1) {
			std::cout << " ";
		}
	}
	if (0 < answer.size()) {
		std::cout << std::endl;
	}

	return (0);
}