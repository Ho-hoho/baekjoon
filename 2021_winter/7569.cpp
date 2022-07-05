#include <iostream>
#include <queue>

using namespace std;
int box[101][101][101] = { 0 };
int vis[101][101][101] = { 0 };
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,-1,0,1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int M, N, H;

typedef struct coor{
	int x,y,z;
	coor(int X, int Y, int Z) : x(X), y(Y), z(Z) {}
}Coor;

bool inBound(int x, int y, int z) {
	if (x >= 0 && x < M &&  y >= 0 && y < N && z >= 0 && z < H)
		return true;
	else
		return false;
}


int main() {
	queue <Coor> q;
	int day = 0;
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> box[m][n][h];
				if (box[m][n][h] == 1) {
					q.push(coor(m, n, h));
					vis[m][n][h] = 1;
				}
				
			}
		}
	}
	while (!q.empty()) {
		Coor cur = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nextX = cur.x + dx[i];
			int nextY = cur.y + dy[i];
			int nextZ = cur.z + dz[i];
			if (inBound(nextX, nextY, nextZ)) {
				if (!vis[nextX][nextY][nextZ] && !box[nextX][nextY][nextZ]) {
					vis[nextX][nextY][nextZ] = vis[cur.x][cur.y][cur.z] + 1;
					box[nextX][nextY][nextZ] = 1;
					q.push(coor(nextX, nextY, nextZ));
				}
			}
		}
	}
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				day = max(day, vis[m][n][h]);
				if (box[m][n][h] == 0) {
					cout << -1;
					return 0 ;
				}

			}
		}
	}
	cout << day-1;
	
	return 0;
}
