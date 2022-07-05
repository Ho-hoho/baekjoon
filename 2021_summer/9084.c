#include <stdio.h>

int arr[21] = { 0 };
int dp[10001] = { 0 };
int n,M;

int init() {
	for (int i = 0; i < 21; i++)
		arr[i] = 0;
	for (int i = 0; i < 10001; i++)
		dp[i] = 0;
	return 0;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		scanf("%d", &M);
		for (int i = 0; i < n; i++) {
			dp[arr[i]] += 1;
			for (int j = 1; j +arr[i]<= M; j++) {
				dp[j + arr[i]] += dp[j] ;
			}/*
			for (int j = 1; j <= M; j++)
				printf("%d ", dp[j]);
			printf("\n");
		}*/
		printf("%d\n", dp[M]);
	}
}
