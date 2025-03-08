#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

#define SUCCESS 0
#define FAILURE 0
#define MAX 50

int N;
std::deque<std::string> word;

int init() {
	std::cin >> N;
	word.resize(N);
	for (int i = 0; i < N; i++) {
		std::cin >> word[i];
	}
	std::sort(word.begin(), word.begin() + N);
	return (0);
}

int solve() {
	for (auto it1 = word.begin(); it1 != word.end(); it1++) {
		loop:
		for (auto it2 = it1 + 1; it2 != word.end(); it2++) {
			if (it2->substr(0, it1->size()) == *it1) {
				it1 = word.erase(it1);
				goto loop;
			}
		}
	}

	std::cout << word.size() << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
