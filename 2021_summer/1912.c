#include <stdio.h>

int dp[100001] = { 0 };
int n,idx=0;
int max = -9999;
int MAX(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i]);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = MAX( dp[i],dp[i-1] + dp[i]);
		max = MAX(max, dp[i]);
	}
	printf("%d", max);
	return 0;
}
