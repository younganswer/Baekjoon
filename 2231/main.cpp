#include <iostream>

int generate(int num);

int main(void) {
	int N;
	
	std::cin >> N;

	for (int i=N-54; i<N; i++) {
		if (generate(i) == N) {
			std::cout << i << std::endl;
			return (0);
		}
	}
	std::cout << 0 << std::endl;
	
	return (0);
}

int generate(int num) {
	int ret = num;

	while (num) {
		ret += num % 10;
		num /= 10;
	}

	return ret;
}