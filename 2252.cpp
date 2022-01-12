#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m, inDegree[32001] = { 0 };
vector<int> a[32001];

void topologySort() {
	int result[100001];
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) 
			q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "ERROR";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		a[t1].push_back(t2);
		inDegree[t2]++;
	}
	topologySort();
	return 0;
}
