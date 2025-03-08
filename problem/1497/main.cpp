#include <iostream>
#include <string>
#include <bitset>

#define SUCCESS 0
#define FAILURE 0
#define MAX_GUITAR 10

typedef struct _Guitar {
	std::string name;
	uint64_t can_play;
}	Guitar;

size_t N, M;
Guitar guitar[MAX_GUITAR];

std::istream &operator>>(std::istream &is, Guitar &guitar) {
	std::string can_play;

	is >> guitar.name >> can_play;
	guitar.can_play = 0;
	for (size_t i = 0; i < can_play.size(); i++) {
		guitar.can_play <<= 1;
		guitar.can_play |= (can_play[i] == 'Y');
	}

	return (is);
}

int init() {
	std::cin >> N >> M;
	for (size_t i = 0; i < N; i++) {
		std::cin >> guitar[i];
	}
	return (0);
}

size_t popcount(uint64_t x) {
	size_t count = 0;

	while (x) {
		count += x & 1;
		x >>= 1;
	}

	return (count);
}

int solve() {
	size_t best_coverage = 0, min_guitar = N;

	for (size_t subset = 0; subset < (1 << N); subset++) {
		uint64_t coverage = 0, used = 0;

		for (size_t j = 0; j < N; j++) {
			if ((subset & (1 << j)) == 0) {
				continue;
			}
			coverage |= guitar[j].can_play;
			used++;
		}
		coverage = popcount(coverage);

		if (best_coverage < coverage) {
			best_coverage = coverage;
			min_guitar = used;
		} else if (best_coverage == coverage) {
			min_guitar = (used < min_guitar) ? used : min_guitar;
		}
	}

	std::cout << (int) ((best_coverage) ? min_guitar : -1) << std::endl;

	return (0);
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
