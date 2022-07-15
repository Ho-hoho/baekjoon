#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[110][110] = {0};
int temp[110][110] = {0};
int temp2[110][110] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m,tick=0;
bool flag;

void fill_air(int x, int y) {
	if (arr[x][y]) { flag = true; return; }
	
	temp[x][y] = 2;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n  && !temp[x+dx[i]][y+dy[i]])
			fill_air(x + dx[i], y + dy[i]);
	}
}

void melt() {
	memset(temp2, 0, sizeof(temp2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				if (temp[i+dx[k]][j+dy[k]] == 2) {
					temp2[i][j]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp2[i][j] >= 2)
				arr[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		memset(temp,0, sizeof(temp));
		flag = false;
		fill_air(0,0);
		if (!flag) break;
		tick++;
		melt();
	}
	cout << tick;
	return 0;
}
