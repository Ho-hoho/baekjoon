#include <iostream>
#include <string.h>

using namespace std;
int mat[301][301] = { 0 };
int temp[301][301] = { 0 };
bool vis[301][301] = { 0 };

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n, m,tick=0;

void melt() {
	for (int i = 1; i < n-1 ; i++) {
		for (int j = 1; j < m - 1; j++) {
			temp[i][j] = mat[i][j];
			vis[i][j] = false;
		}
	}
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m - 1; j++) {
			for (int k = 0; k < 4; k++) {
				if (!mat[i + dx[k]][j + dy[k]]) {
					temp[i][j] -= 1;
				}
			}
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			mat[i][j] = temp[i][j];
			if (mat[i][j] < 0) mat[i][j] = 0;
		}
	}
}

void dfs(int x, int y) {
	vis[x][y] = true;

	for (int k = 0; k < 4; k++) {
		if(mat[x + dx[k]][y + dy[k]] && !vis[x + dx[k]][y + dy[k]])
			dfs(x + dx[k], y + dy[k]);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	while (1) {
		bool flag= false;
		int chunk = 0;

		tick++;
		melt();

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (mat[i][j] && !vis[i][j]) {
					dfs(i,j);
					chunk++;
				}
			}
		}
		if (chunk == 0) {
			tick = 0;
			break;
		}
		else if (chunk >= 2) break;
		
	}
	cout << tick;
	return 0;
}
