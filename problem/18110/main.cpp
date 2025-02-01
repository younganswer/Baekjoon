#include <iostream>
#include <cmath>

#define MIN_DIFFICULTY 1
#define MAX_DIFFICULTY 30

using namespace std;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long double answer = 0;
	int 		n;
	int			arr[(MAX_DIFFICULTY + 1)] = {0, };
	
	cin >> n;
	if (n == 0) {
		cout << 0 << '\n';
		return (0);
	}
	for (int i=0, difficulty; i<n; i++) {
		cin >> difficulty;
		arr[difficulty]++;
	}
	for (int i=0, j=MIN_DIFFICULTY; i<n && j<=MAX_DIFFICULTY;) {
		if (arr[j] == 0) {
			j++;
			continue;
		}

		arr[j]--;
		if (round(n * 0.15) <= i && i < n - round(n * 0.15))
			answer += j;
		i++;
	}
	cout << round(answer / (n - 2 * round(n * 0.15))) << '\n';
	return (0);
} // end of main