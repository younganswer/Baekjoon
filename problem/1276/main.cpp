#include <iostream>
#include <vector>
#include <map>

#define SUCCESS 0
#define FAILURE 0
#define MAX 10000

int N;
int level[MAX] = {0, };

typedef int Level;

typedef struct _Coordinate {
	size_t x, y;
} Coordinate;

std::map<Level, std::vector<Coordinate>> map;

int init() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		size_t level, x, y;
		std::cin >> level >> x >> y;
		map[level].push_back({x, y - 1});
	}
	return (0);
}

int solve() {
	int answer = 0;

	for (auto iter = map.begin(); iter != map.end(); iter++) {
		for (size_t i = 0; i < iter->second.size(); i++) {
			answer += 2 * iter->first - level[iter->second[i].x] - level[iter->second[i].y];
			for (size_t j = iter->second[i].x; j <= iter->second[i].y; j++) {
				level[j] = iter->first;
			}
		}
	}

	std::cout << answer << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
