#include <stdio.h>
int dp[1010][1010] = { 0 };
int n, m;
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &dp[i][j]);
		}
	}
	for (int i = 2; i <= n; i++)
		dp[i][1] += dp[i - 1][1];
	for (int j = 2; j <= m; j++)
		dp[1][j] += dp[1][j-1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] += max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}

	printf("%d", dp[n][m]);
	
}
