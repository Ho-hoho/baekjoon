#include <stdio.h>

int n, k;
int dp[1001][1001] = { 0 };   
int main() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		dp[i][1] = i;
	}
	for (int i = 4; i <= n; i++) {
		for (int j = 2; j <= i/2; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j])%1000000003;
		}
	}
	printf("%d", dp[n][k]);
	return  0;
}
