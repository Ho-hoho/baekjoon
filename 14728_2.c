#include <stdio.h>

int n, t;
int K[1001] = { 0 };
int S[1001] = { 0 };
int dp[10001] = { 0 };
int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &K[i], &S[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = t; j >= 1; j--) {
			if (K[i] <= j) {
				dp[j] = MAX(dp[j], dp[j - K[i] ] + S[i]);
			}
		}
	}
	printf("%d", dp[t]);
}
