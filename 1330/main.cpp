#include <iostream>

int	main(void) {
	int T;

	std::cin >> T;

	while (T--) {
		int H, W, N;
		
		std::cin >> H >> W >> N;

		int row = (N - 1) % H + 1;
		int column = (N - 1) / H + 1;

		std::cout << row;
		if (column < 10) {
			std::cout << '0';
		}
		std::cout << column;
		std::cout << std::endl;
	}

	return (0);
}