#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX 200000

int					N;
std::vector<int>	v;

bool init(void) {
	std::cin >> N;
	if (std::cin.fail() || N < 1 || MAX < N) {
		return (false);
	}
	v.resize(N);
	for (int i = 0; i < N; i++) {
		std::cin >> v[i];
		if (std::cin.fail()) {
			return (false);
		}
	}
	return (true);
}

int main(int argc, char **argv) {
	if (init() == false) {
		std::cout << "Invalid input" << std::endl;
		return (1);
	}

	std::unordered_map<int, int> cnt;
	int max_sz = 0, left = 0;

	for (int right=0; right<N; right++) {
		cnt[v[right]]++;

		while (2 < cnt.size()) {
			cnt[v[left]]--;
			if (cnt[v[left]] == 0) {
				cnt.erase(v[left]);
			}
			left++;
		}

		max_sz = std::max(max_sz, right - left + 1);
	}

	std::cout << max_sz << std::endl;
	
	return (0);
}