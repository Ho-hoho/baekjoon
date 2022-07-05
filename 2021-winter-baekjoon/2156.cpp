#include <iostream>
#include <algorithm>
using namespace std;
int n;
int wine[10001] = { 0 };
int dp[10001][3] = { 0 };
int maxdp[10001][2] = { 0 };

void solve() {
	dp[1][0] = dp[1][1] = wine[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][2], max(dp[i - 2][0], dp[i - 2][1])) + wine[i];
		dp[i][1] = dp[i - 1][0] + wine[i];
		dp[i][2] = max(dp[i-1][2],max(dp[i - 1][0], dp[i - 1][1]));
	}
	printf("%d", max(dp[n-1][1],max(dp[n][0], dp[n][1])));
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];
	solve();
}
