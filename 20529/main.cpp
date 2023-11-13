#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#define MAX 100000

using namespace std;

int		T, N;
string	mbti[MAX];

bool	init(void);
int		solve(void);
int		distance(string a, string b);

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		if (init() == false) {
			cout << "Fail to init" << endl;
			return (1);
		}
		cout << solve() << endl;
	}
	return (0);
} // end of main

bool	init(void) {
	cin >> N;
	if (N < 1 || MAX < N) {
		return (false);
	}

	for (int i=0; i<N; i++) {
		cin >> mbti[i];
	}
	return (true);
}

int	solve(void) {
	int ret = 2147483647;

	if (32 < N) {
		return (0);
	}

	for (int i=0; i<N-2; i++) {
		for (int j=i+1; j<N-1; j++) {
			for (int k=j+1; k<N; k++) {
				ret = min(ret, distance(mbti[i], mbti[j]) + distance(mbti[j], mbti[k]) + distance(mbti[k], mbti[i]));
			}
		}
	}
	return (ret);
}

int	distance(string a, string b) {
	int	ret = 0;

	for (int i=0; i<4; i++) {
		if (a[i] != b[i]) {
			ret++;
		}
	}
	return (ret);
}