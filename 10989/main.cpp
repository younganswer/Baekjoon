#include <iostream>
#include <string>

#define MAX 10001

int N, arr[MAX] = {0};

int main(void) {
	std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

	std::cin >> N;

	for (int i=0; i<N; i++) {
		int num;

		std::cin >> num;
		arr[num]++;
	}

	for (int i=0; i<MAX; i++) {
		for (int j=0; j<arr[i]; j++) {
			std::cout << i << '\n';
		}
	}

	return (0);
}