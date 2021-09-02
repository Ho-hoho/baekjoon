#include <iostream>
#include <algorithm>
using namespace std;

int  N, M , K;
int ans = -1;
string arr[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> K;
	for (int i = 0; i < N; i++) {
		int zero = 0;
		for (int j = 0; j < M; j++)
			if (arr[i][j] == '0')
				zero++;
		int sum = 0;
		if (zero <= K && zero % 2 == K % 2) {
			for (int j = i ; j <N; j++)
				if (arr[i] == arr[j])
					sum++ ;
		}
		ans = max(ans, sum);
	}
	cout << ans;
}
