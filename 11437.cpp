#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define MAX 50001
#define MAX_H (int)floor(log2(MAX)) 
using namespace std;
int N, M;
vector<int> adj[MAX];
int parent[MAX][17];
int depth[MAX];

void make_depth(int cur){ // depth 정보를 만드는 함수
	for (int next : adj[cur]) { // range based for문
		if (depth[next] == -1) {
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			make_depth(next);
		}
	}
}

void connection() {
	for (int k = 1; k <= MAX_H; k++) {
		for (int cur = 1; cur <= N; cur++) {
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) { 
		int tmp = u;
		u = v;
		v = tmp;
	}

	int diff = depth[u] - depth[v];
	for (int i = 0; diff != 0; i++) {
		if (diff % 2 == 1)
			u = parent[u][i];
		diff /= 2; 
	}

	if (u != v) {
		for (int i = MAX_H; i >= 0; i--) {
			if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	return u;
}

int main() {
	cin >> N;
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	depth[1] = 0;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	make_depth(1);
	connection();
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}
}
