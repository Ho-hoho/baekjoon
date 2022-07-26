#include <iostream>
#include <vector>

using namespace std;
int n,a,b,c;
vector <pair<int,int>> arr[100001];
bool vis[100'001] = {0};
pair<int, int> ans;
void dfs(int node, int len) {
	vis[node] = true;
	for (auto e : arr[node]) {
		if (!vis[e.first]) {
			if (len + e.second > ans.second) {
				ans = { e.first,len + e.second };
			}
			dfs(e.first, len + e.second);
		}
	}
	vis[node] = false;
	return;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b != -1) cin >> c;
			else break;
			arr[a].push_back({ b,c });
		}
	}
	ans = { 0,0 };
	dfs(1, 0);
	ans.second = 0;
	dfs(ans.first, 0);
	cout << ans.second;
}
