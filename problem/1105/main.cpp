#include <iostream>
#include <string>

#define SUCCESS 0
#define FAILURE 0
#define MAX 2e10

std::string L, R;

int init() {
	std::cin >> L >> R;
	return (0);
}

int solve() {
	if (L.size() != R.size()) {
		std::cout << "0" << std::endl;
		return (0);
	}

	int cnt = 0;
	
	while (0 < L.size() && L[0] == R[0]) {
		cnt += (L[0] == '8');
		
		L = L.substr(1);
		R = R.substr(1);
	}

	std::cout << cnt << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
