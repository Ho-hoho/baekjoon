#include <stdio.h>

int pend[31] = { 0 };
int bead[8] = { 0 };
int N, M ,low,high;
int dp[31][40010] = { 0 };
const int pivot = 20000;
int MAX(int a, int b) {
	return a > b ? a : b;
}
int init() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 40010; j++) {
			dp[i][j] = 0;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &pend[i]);
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
		scanf("%d", &bead[i]);
	int idx = 0;
		init();
		dp[0][pivot] = 1;
		low = pivot - pend[0];
		dp[0][low] = 1;
		high = pivot + pend[0];
		dp[0][high] = 1;
		high = pivot + pend[0];
		for (int i = 1; i < N; i++) {		
			for (int j = low; j <=high; j++) {
				if (dp[i - 1][j] == 1) {
					dp[i][j] = dp[i - 1][j];
					dp[i][j - pend[i]] = dp[i - 1][j];
					dp[i][j + pend[i]] = dp[i - 1][j];
				}
				
			}
			low -= pend[i];
			high += pend[i];
		}
		
		
		
		for (int idx = 1; idx <= M; idx++) {
			if (bead[idx] > 15000)
				printf("N ");
			else if (dp[N - 1][pivot + bead[idx]])
				printf("Y ");
			else
				printf("N ");
		}
		
		return 0;
	
}
