#include <stdio.h>
int dp[2001][2001] = { 0 };
int arr[2001] = { 0 };
int n,m;

int print_dp() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i][i] = 1;
		if (arr[i] == arr[i - 1])
			dp[i - 1][i] = 1;
	}
	
	for (int d = 1; d <= n; d++) {
		for (int tx = 1; tx + d <= n; tx++) {
			int ty = tx + d;
			if (arr[tx] == arr[ty] && dp[tx + 1][ty - 1])
				dp[tx][ty] = 1;
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
}
