#include <stdio.h>

int dp[100001][2] = { 0 };
int arr[100001] = { 0 };
int n,idx=0;
int max = -9999;
int MAX(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i][0] =  dp[i][1] = arr[i];
	}
	max = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = MAX( arr[i],dp[i-1][0] + arr[i]);
		dp[i][1] = MAX(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		max = MAX(max, MAX(dp[i][0],dp[i][1]));
	}
	printf("%d", max);
	return 0;
}
