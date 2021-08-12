#include <stdio.h>
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[501][501];
int dp[501][501];
int n, m;

int MAX(int a, int b) {
	return a > b ? a : b;
}
int dfs(int y, int x) {
	
	if (dp[y][x] == -1) {
		dp[y][x] = 1;
		int noway = 0;
		for (int k = 0; k < 4; k++) {
			int newy = y + dy[k];
			int newx = x + dx[k];
			if (newx > 0 && newx <= n && newy > 0 && newy <= n && arr[y][x] < arr[newy][newx]) {
				dp[y][x] = MAX(dp[y][x], dfs(newy, newx)+1);
			}
		}
	}
	return dp[y][x];
}

int main() {
	int ans = 0;
	scanf("%d ", &n);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
			arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = MAX(ans, dfs(i, j));
		}	
	}
	
	printf("%d", ans);
	
}
