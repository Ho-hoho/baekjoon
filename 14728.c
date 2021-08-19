#include <stdio.h>

int n, t;
int K[1001] = { 0 };
int S[1001] = { 0 };
int dp[101][10001] = { 0 };
int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &K[i], &S[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= K[i]) {
				dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - K[i]] + S[i]) ;
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	printf("%d", dp[n][t]);
}
