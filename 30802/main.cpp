#include <iostream>

int	main(void) {
	int N;
	int sizes[6];
	int T, P;

	std::cin >> N;
	for (int i=0; i<6; i++) {
		std::cin >> sizes[i];
	}
	std::cin >> T >> P;

	int bundles = 0;
	for (int i=0; i<6; i++) {
		if (sizes[i] == 0) {
			continue;
		}
		bundles += (sizes[i] - 1) / T + 1;
	}
	std::cout << bundles << std::endl;
	
	std::cout << N / P << ' ' << N % P << std::endl;
	return (0);
}