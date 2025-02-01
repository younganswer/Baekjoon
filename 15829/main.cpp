#include <iostream>
#include <string>

unsigned long long r=1, M=1234567891;

int main(void) {
	int N;
	std::string	str;
	int	a, ans = 0;

	std::cin >> N >> str;
	for (unsigned long i=0; i<str.length(); i++) {
		a = str[i] - 'a' + 1;
		ans = (ans + r * a) % M;
		r = (r * 31) % M;
	}
	std::cout << ans << std::endl;
	
	return (0);
}