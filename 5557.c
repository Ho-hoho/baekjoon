#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int arr[101] = { 0 };
long long dp[101][21] = { 0 };
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1][arr[1]]++;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + arr[i] <= 20)
					dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	printf("%lld ", dp[n - 1][arr[n]]);
}
