#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, k;
long long dp[201][201] = { 0 };
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int j = 1; j < k; j++) {
		for (int i = 0; i <= n; i++) {
			for (int a = 0; a <= i; a++) {
				dp[i][j] += (dp[a][j - 1]%1000000000);
			}
		}
	}
	/*
	for (int i = 0; i <= n; i++) {
		for(int j=0;j < k;j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	
	printf("%lld",dp[n][k - 1]%1000000000);
}
