#include <iostream>
#include <string>
#include <map>

#define SUCCESS 0
#define FAILURE 0
#define MAX 10

std::string str;
std::map<char, int> map;

int init() {
	std::cin >> str;
	for (size_t i = 0; i < str.size(); i++) {
		map[str[i]]++;
	}
	return (0);
}

int dfs(const std::string &cur) {
	int ret = 0;

	if (cur.size() == str.size()) {
		return (1);
	}

	for (std::map<char, int>::const_iterator iter=map.begin(); iter!=map.end(); iter++) {
		if (iter->second == 0 || (0 < cur.size() && cur[cur.size() - 1] == iter->first)) {
			continue;
		}
		map[iter->first]--;
		ret += dfs(cur + iter->first);
		map[iter->first]++;
	}

	return (ret);
}

int solve() {
	if (map.size() == MAX) {
		std::cout << 3628800 << std::endl;
	} else {
		std::cout << dfs("") << std::endl;
	}
	
	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
