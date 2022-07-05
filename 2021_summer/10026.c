#include <stdio.h>
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
char tmp[101][101];
int arr[101][101] = { 0 };
int dis[101][101] = { 0 };
int vis[101][101] = { 0 };
int vis_dis[101][101] = { 0 };
int n,area=0;

int dfs(int y,int x) {
	vis[y][x] = 1;
	for (int k = 0; k < 4; k++) {
		int newy = y + dy[k];
		int newx = x + dx[k];
		if (arr[y][x] == arr[newy][newx] && !vis[newy][newx]) {
			dfs(newy, newx);
		}
	}
	arr[y][x] = 0;
	return 0;
}
int dfs_dis(int y, int x) {
	vis_dis[y][x] = 1;
	for (int k = 0; k < 4; k++) {
		int newy = y + dy[k];
		int newx = x + dx[k];
		if (dis[y][x] == dis[newy][newx] && !vis_dis[newy][newx]) {
			dfs_dis(newy, newx);
		}
	}
	dis[y][x] = 0;
	return 0;
}
int main() {
	scanf("%d", &n);
	scanf("\n");
	for (int i = 0; i < n; i++) {
		scanf("%s", &tmp[i]);
		
	}
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j] == 'R') {
				arr[i+1][j+1] = 1;
				dis[i+1][j+1] = 1;
			}
			else if (tmp[i][j] == 'G') {
				arr[i+1][j + 1] = 2;
				dis[i + 1][j + 1] = 1;
			}
			else if (tmp[i][j] == 'B') {
				arr[i + 1][j + 1] = 3;
				dis[i + 1][j + 1] = 3;
			}

		}
	}
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n ; j++) {
			if (arr[i][j] != 0) {
				area += 1;
				dfs(i, j);
			}
		}	
	}
	printf("%d ", area);
	area = 0;
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n ; j++) {
			if (dis[i][j] != 0) {
				area += 1;
				dfs_dis(i, j);
			}
		}
	}
	printf("%d ",area);

}
