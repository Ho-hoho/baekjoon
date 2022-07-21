#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,ans=0;
int arr[100001];
bool vis[100001];
bool finished[100001];

void dfs(int node) {
	vis[node] = true;
	int next = arr[node];

	if (!vis[next]) {
		dfs(next);
	}
	else if (!finished[next]) {
		for (int i = next; i != node; i = arr[i]) {
			ans++;
		}
		ans++;
	}
	finished[node] = true;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc;

	cin >> tc;

	while(tc--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			vis[i] = false;
			finished[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) dfs(i);
		}

		cout << n - ans << "\n";
	}


	return 0;
}
