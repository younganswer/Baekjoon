#include <iostream>
#include <string>

#define SUCCESS 0
#define FAILURE 0
#define MAX 30

int N;
std::string line[MAX];
bool alpha[26] = {0, };

class Shortcut {
public:
    std::string line;
    size_t pos;
    
    friend std::ostream& operator<<(std::ostream& os, const Shortcut& shortcut) {
        os << shortcut.line.substr(0, shortcut.pos)
           << '[' << shortcut.line[shortcut.pos] << ']'
           << shortcut.line.substr(shortcut.pos + 1);
        return os;
    }
};

int charToIndex(char c) {
    return ('a' <= c && c <= 'z') ? c - 'a' : c - 'A';
}

int init() {
    std::cin >> N;
    std::cin.ignore();
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line[i]);
    }
    return 0;
}

int solve() {
    for (int i = 0; i < N; i++) {
        for (size_t j = 0; j < line[i].length(); j++) {
            if (j != 0 && line[i][j - 1] != ' ') {
				continue;
			}
			int idx = charToIndex(line[i][j]);
			if (alpha[idx]) {
				continue;
			}
			alpha[idx] = true;
			std::cout << Shortcut{line[i], j} << std::endl;
			goto loop;
        }
        
		for (size_t j = 0; j < line[i].length(); j++) {
			if (line[i][j] == ' ') {
				continue;
			}
            int idx = charToIndex(line[i][j]);
            if (alpha[idx]) {
				continue;
			}
			alpha[idx] = true;
			std::cout << Shortcut{line[i], j} << std::endl;
			goto loop;
        }

        std::cout << line[i] << std::endl;
        
    	loop: ;
    }

	return (0);
}

int main(int argc, char **argv) {
    (void) argc;
    (void) argv;

    return ((init() == 0 && solve() == 0) ? SUCCESS : FAILURE);
}
