#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int t, n, k,w;
int D[1001] = { 0 };
int inDegree[1001] = { 0 };
int level[1001] = { 0 };
int dp[1001] = { 0 };
vector<int> arr[1001];


void solve() {
	queue<int> q2,q;
	int result[1001];
	int sum = 0;
	bool flag = false;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q2.push(i);
		}
	}
	while (!q2.empty()) {
		q.push(q2.front()); 
		level[q2.front()] = 1;
		q2.pop();
		for (int i = 1; i <= n; i++) {
			if (q.empty()) {
				break;
			}
			int x = q.front(); q.pop();
			result[i] = x;
			for (int j = 0; j < arr[x].size(); j++) {
				int y = arr[x][j];
				if (--inDegree[y] == 0) {
					q.push(y);
					level[y] = level[x] + 1;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			int maxnum = 0;
			for (int j = 1; j <= n; j++) {
				if (level[j] == i) {
					level[j] = 0;
					maxnum = max(maxnum, D[j]);
					if (j == w) {
						flag = true;
						break;
					}
				}
			}
			sum += maxnum;
			if (flag) {
				cout << sum << "\n";
				return;
			}
		}
		sum = 0;
	}
	return;

}

void solve2() {
	queue<int> q;
	int result[1001];
	int sum = 0;
	bool flag = false;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
		dp[i] = D[i];
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			break;
		}
		int x = q.front(); q.pop();
		result[i] = x;
		for (int j = 0; j < arr[x].size(); j++) {
			int y = arr[x][j];
			dp[y] = max(dp[y], dp[x] + D[y]);
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	cout << dp[w]<<"\n";

	return;

}
int main() {
	
	cin >>t;
	while (t--) {
		cin >> n >> k;
		memset(inDegree, 0, sizeof(int) * 1001);
		memset(dp, 0, sizeof(int) * 1001);
		
		for (int i = 1; i <= n; i++) {
			cin >> D[i];
			arr[i].clear();
		}
		for (int i = 1; i <= k; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			arr[t1].push_back(t2);
			inDegree[t2]++;
		}
		cin >> w;
		//solve();
		solve2();
	}
	
	return 0;
}
