#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int k;
int dp[1000001][11];
string arr;

int dfs(string snum, int depth) {
	if (depth == 0)
		return stoi(snum);

	int num = stoi(snum);
	int& ret = dp[num][depth];

	if (ret >= 0) return ret;

	for (int i = 0; i < snum.length(); i++) {
		for (int j = i + 1; j < snum.length(); j++) {
			if (i == 0 && snum[j] == '0')
				continue;
			swap(snum[i], snum[j]);
			ret = max(ret, dfs(snum, depth - 1));
			swap(snum[i], snum[j]);
		}
	}
	return ret;
	
	/*if (dp[num][depth] >= 0) return dp[num][depth];

	for (int i = 0; i < snum.length(); i++) {
		for (int j = i + 1; j < snum.length(); j++) {
			if (i == 0 && snum[j] == '0')
				continue;
			swap(snum[i], snum[j]);
			dp[num][depth] = max(dp[num][depth], dfs(snum, depth - 1));
			swap(snum[i], snum[j]);
		}
	}
	return dp[num][depth];*/

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> arr >> k;

	memset(dp, -1, sizeof(dp));
	cout << dfs(arr, k);
	return 0;
}
