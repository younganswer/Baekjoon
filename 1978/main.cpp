#include <iostream>
#include <math.h>

#define MAX 1000


int main(void) {
	bool nums[(MAX) + 1];

	nums[0] = nums[1] = false;
	for (int i=2; i<(MAX) + 1; i++) {
		nums[i] = true;
	}
	for (int i=2; i<std::sqrt((MAX) + 1); i++) {
		if (nums[i] == false) {
			continue;
		}
		for (int j=2*i; j<(MAX) + 1; j+=i) {
			nums[j] = false;
		}
	}
	
	int N, cnt = 0;
	
	std::cin >> N;
	for (int i=0; i<N; i++) {
		int num;

		std::cin >> num;
		if (nums[num]) {
			cnt++;
		}
	}
	std::cout << cnt << std::endl;
	return (0);
}