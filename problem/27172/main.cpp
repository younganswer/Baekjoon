#include <iostream>
#include <vector>

#define MAX_NUM 100000
#define MAX_VAL 1000000

using namespace std;

int			N;
vector<int>	v;
bool		arr[(MAX_VAL) + 1] = {false, };
int			answer[(MAX_VAL) + 1] = {0, };

bool	init(void);
bool	solve(void);

int	main(void) {
	if (init() == false) {
		cout << "Fail to initailize" << endl;
		return (1);
	}
	if (solve() == false) {
		cout << "Fail to solve" << endl;
		return (1);
	}
	return (0);
} // end of main

bool	init(void) {
	cin >> N;

	if (N < 2 || MAX_NUM < N) {
		return (false);
	}

	for (int i=0; i<N; i++) {
		int	val;

		cin >> val;
		if (val < 1 || MAX_VAL < val) {
			return (false);
		}
		v.push_back(val);
		arr[val] = true;
	}
	return (true);
}

bool	solve(void) {
	for (int i=0; i<N; i++) {
		int	cur = v[i];

		for (int j=cur+cur; j<=MAX_VAL; j+=cur) {
			if (arr[j] == false) {
				continue;
			}
			answer[cur]++;
			answer[j]--;
		}
	}
	for (int i=0; i<N; i++) {
		cout << answer[v[i]] << ' ';
	}
	cout << endl;
	return (true);
}