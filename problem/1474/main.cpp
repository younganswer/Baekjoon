#include <iostream>
#include <string>

#define SUCCESS 0
#define FAILURE 0
#define MAX 10

int N, M;
std::string word[MAX];
int underscore_len = 0;

int init() {
	int word_len = 0;
	
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> word[i];
		word_len += word[i].length();
	}
	underscore_len = M - word_len;
	
	return (0);
}

int solve() {
	size_t len_per_underscore = underscore_len / (N - 1);
	size_t len_remain = underscore_len % (N - 1);
	std::string underscore[N - 1];

	for (int i = 0; i < N - 1; i++) {
		underscore[i] = std::string(len_per_underscore, '_');
	}
	
	for (int i = 1; i < N && 0 < len_remain; i++) {
		if (!std::islower(word[i][0]) || underscore[i - 1].length() != len_per_underscore) {
			continue;
		}
		underscore[i - 1].push_back('_');
		len_remain--;
	}

	for (int i = N - 1; 0 < i && 0 < len_remain; i--) {
		if (!std::isupper(word[i][0]) || underscore[i - 1].length() != len_per_underscore) {
			continue;
		}
		underscore[i - 1].push_back('_');
		len_remain--;
	}

	for (int i = 0; i < N; i++) {
		std::cout << word[i];
		if (i < N - 1) {
			std::cout << underscore[i];
		}
	}
	std::cout << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
