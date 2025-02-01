#include <iostream>

int gcd(int a, int b);

int main(void) {
	int a, b;

	std::cin >> a >> b;
	if (a < b) {
		std::swap(a, b);
	}
	int res = gcd(a, b);

	std::cout << res << std::endl;
	std::cout << a * b / res << std::endl;
	
	return (0);
}

int gcd(int a, int b) {
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return (a);
}