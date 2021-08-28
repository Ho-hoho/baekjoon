#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define INF 1111111
int N, M;
int adj[1001][1001] = { 0 };
int selected[1001] = { 0 };
int dist[1001] = { 0 };
int ans = 0;
int get_min_vertex(int n) {
	int v=0;
	int min_dist = INF;
	for (int i = 1; i <= n; i++) {
		if (!selected[i] && (dist[i] < min_dist)) {
			v = i;
			min_dist = dist[i];
		}
	}
	return v;
}
int prim(int s, int n) {
	for (int u = 1; u <= n; u++) {
		dist[u] = INF;
		selected[u] = 0;
	}
	dist[s] = 0; // here?
	for (int i = 1; i <= n; i++) {
		int u = get_min_vertex(n);
		selected[u] = 1;
		if (dist[u] == INF) 
			return 0;
		ans += dist[u];
		for (int v = 1; v <= n; v++) {
			if (adj[u][v] != INF) {
				if (!selected[v] && adj[u][v] < dist[v])
					dist[v] = adj[u][v];
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &N,&M);
	memset(adj, INF , sizeof(adj) );
	for (int i = 0; i < M; i++) {
		int from, to, c;
		scanf("%d %d %d", &from, &to, &c);
		adj[from][to] = c;
		adj[to][from] = c;
	}
	prim(1, N);
	printf("%d", ans);

	return 0;
}
