#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N,ans =-1;
int arr[501][501] ={0};
int dp[501][501] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}
	ans = dp[0][0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] += dp[i - 1][0];
			else if (j == i)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += max(dp[i-1][j - 1], dp[i-1][j]);

			if (i == N - 1)
				ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
	
	return 0;
}
