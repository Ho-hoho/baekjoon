#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int adj[101][101] = { 0 };
#define MAX 100000001

void solve() {
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
					adj [i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
				
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || adj[i][j] >= MAX) { 
				cout << "0 ";
			}
			else cout << adj[i][j] << ' ';
		}
		cout << "\n";
	}
}

int main() {
	cin >> n >> m;
	fill(&adj[0][0], &adj[101][0], MAX );
	
	for (int i = 0; i < m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		adj[t1][t2] = min(adj[t1][t2],t3);
	}
	solve();
}
