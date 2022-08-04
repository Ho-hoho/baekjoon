#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 1000010

using namespace std;

int N;
int dp[MAX], memo[MAX];
vector<pair<int, int>> arr;
stack <int> ans;
int len = 0,a,b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	

	dp[len++] = arr[0].second;
	memo[0] = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i].second > dp[len - 1]) {
			dp[len++] = arr[i].second;
			memo[i] = len-1;
		}
		else {
			int* iter = lower_bound(dp, dp + len, arr[i].second);
			*iter = arr[i].second;
			memo[i] = iter - dp;
		}
	}
	cout << N - len << "\n";
	int cnt = len - 1;
	for (int i = N-1; i >= 0; i--) {
		if (cnt == memo[i]) {
			ans.push(i);
			cnt--;
		}
	}
	a = ans.top();
	ans.pop();
	for (int i = 0; i < N; i++) {
		if (a == i) {
			if (ans.empty()) continue;
			a = ans.top();
			ans.pop();
		}
		else {
			cout << arr[i].first << "\n";
		}
	}
	return 0;
}
