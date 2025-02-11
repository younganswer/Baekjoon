#include <iostream>
#include <iomanip>

#define MAX 35

class Coordinate {
public:
	int x, y;
};

int N;
Coordinate coordinates[MAX];

int init() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> coordinates[i].x >> coordinates[i].y;
	}
	return (0);
}

double area(Coordinate a, Coordinate b, Coordinate c) {
	return std::abs((double) (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x)) / 2;
}

int solve() {
	double answer = 0;
	
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				double temp = area(coordinates[i], coordinates[j], coordinates[k]);

				answer = (answer < temp) ? temp : answer;
			}
		}
	}

	std::cout << std::fixed << std::setprecision(9) << answer << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	if (init() != 0) {
		return (-1);
	}

	if (solve() != 0) {
		return (-1);
	}

	return (0);
}
