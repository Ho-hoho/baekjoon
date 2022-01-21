#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int N=0, d;
int arr[101] = { 0 };
int max_num = 0;


int solve(int n) {
	int vis = 0;
	for (int i = 0; i < d; i++) {
		arr[i] = n % d;
		n = n / d;
	}	
	while (n <= max_num) {
		vis = 0;
		arr[0] += 1; N++;
		for (int i = 0; i < d; i++) {
			if (arr[i] == d) {
				arr[i + 1]++; arr[i] = 0;
				break;
			}
		}
		for (int i = 0; i < d; i++) {
			if (!(vis & (1 << arr[i]))) {
				vis = vis | (1 << arr[i]);
				if (vis == (1 << d) - 1 && arr[d-1] != 0)
					return N;
			}
			else break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> d;

	
	for (int i = 0; i < d; i++) {
		max_num += i * pow(d, i);
	}
	if (N >= max_num) {
		cout << -1 << "\n";
	}
	else {
		cout << solve(N);
	}

	return 0;
}
