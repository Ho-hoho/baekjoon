#include <iostream>
#include <algorithm>
#define SMALL 1
#define BIG 2

using namespace std;
int N,M;
int adj[101][101] = { 0 };

void solve2() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (adj[i][k] == adj[k][j] && !adj[i][j])
					adj[i][j] = adj[i][k]; 
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int cnt = -1;

		for (int j = 1; j <= N; j++) {
			if (!adj[i][j])
				cnt++;
		}
		printf("%d\n", cnt);
	}


}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (adj[i][j]) {
				for (int k = 1; k <= N; k++) {
					if (adj[j][k] == adj[i][j])
						adj[i][k] = adj[i][j];
				}
			}

		}
	}
	for (int i = 1; i <= N; i++) {
		int cnt = -1;
		for (int j = 1; j <= N; j++) {
			if (!adj[i][j])
				cnt++;
		}
		printf("%d\n", cnt);
	}


}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = BIG;
		adj[b][a] = SMALL;
	}
	//solve(); this method didnt pass the test. WHY?
	solve2();

	return 0;
}
