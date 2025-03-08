#include <iostream>

#define SUCCESS 0
#define FAILURE 0

typedef struct _Coordinate {
	int x;
	int y;
}	Coordinate;

std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate) {
	os << coordinate.x << " " << coordinate.y;
	return (os);
}

Coordinate destination, from, direction;

int init() {
	std::cin >> destination.x >> destination.y;
	std::cin >> from.x >> from.y;
	std::cin >> direction.x >> direction.y;
	return (0);
}

int gcd(int a, int b) {
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

int solve() {
	if (direction.x == 0 && direction.y == 0) {
		std::cout << from << std::endl;
		return (0);
	}
	
	if (direction.x == 0) {
		std::cout << from.x << " " << destination.y << std::endl;
		return (0);
	}
	
	if (direction.y == 0) {
		std::cout << destination.x << " " << from.y << std::endl;
		return (0);
	}

	int min = (destination.x - from.x) * (destination.x - from.x) + (destination.y - from.y) * (destination.y - from.y);
	Coordinate answer = from, current = from;
	int divisor = gcd(direction.x, direction.y);
	direction.x /= divisor;
	direction.y /= divisor;

	while (-100 <= current.x && current.x <= 100 && -100 <= current.y && current.y <= 100) {
		int distance = (destination.x - current.x) * (destination.x - current.x) + (destination.y - current.y) * (destination.y - current.y);
		if (distance < min) {
			min = distance;
			answer = current;
		}
		current.x += direction.x;
		current.y += direction.y;
	}

	std::cout << answer << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
