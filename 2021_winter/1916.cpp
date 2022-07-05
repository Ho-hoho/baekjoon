#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 987654321

vector <pair<int, int>> adj[1001];
int N , M;
int src, des;
int dis[1001] = { 0 };

void solve(int src) {
	dis[src] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push(make_pair( src, 0 ));
	while (!pq.empty()) {
		int cur = pq.top().first;
		int curdis = -pq.top().second;
		pq.pop();
		if (curdis > dis[cur]) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nextdis = curdis + adj[cur][i].second;
			if (dis[next] > nextdis) {
				dis[next] = nextdis;
				pq.push(make_pair( next, -nextdis ));
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		dis[i] = MAX;
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		adj[x].push_back(make_pair(y,z));
	}
	
	cin >> src >> des;
	solve(src);
	cout << dis[des];
}
