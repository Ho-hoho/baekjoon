#include <stdio.h>
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[501][501];
int dp[501][501];
int n, m;

int dfs(int y, int x) {

	if (y == n && x == m) {
		return 1;
	}
	else if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int k = 0; k < 4; k++) {
			int newy = y + dy[k];
			int newx = x + dx[k];
			if (newx > 0 && newx <= m && newy > 0 && newy <= n && arr[y][x] > arr[newy][newx]) {
				dp[y][x] += dfs(newy, newx);
			}
		}
	}
	return dp[y][x];
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = -1;
			arr[i][j] = 10001;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d\n ", dfs(1, 1));



}
