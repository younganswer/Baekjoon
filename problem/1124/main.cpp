#include <iostream>
#include <math.h>

#define SUCCESS 0
#define FAILURE 0
#define MAX 100000

int A, B;
bool is_prime[MAX + 1] = { true, };

int init() {
	std::cin >> A >> B;

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX; i++) {
		is_prime[i] = true;
	}

	for (int i = 2; i <= std::sqrt(MAX); i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}
	
	return (0);
}

int is_under_prime(int n) {
	int cnt = 0;

	for (int i = 2; i <= MAX / 2 && 1 < n; i++) {
		if (!is_prime[i]) {
			continue;
		}
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
	}
	
	return (is_prime[cnt]);
}

int solve() {
	int cnt = 0;

	for (int i = A; i <= B; i++) {
		cnt += is_under_prime(i);
	}

	std::cout << cnt << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
