#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;

int arr[1000001], dp[1000001], memo[1000001],lis[1000001];
int ans=0,ans_idx=0,lis_cnt=0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	memset(dp, 0, sizeof(dp));
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				memo[i] = j;
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
			ans_idx = i;
		}
	}
	while (1) {
		lis[lis_cnt++] = arr[ans_idx];
		if (memo[ans_idx] == -1) break;
		ans_idx = memo[ans_idx];
	}
	cout << ans << "\n";
	for (int i = lis_cnt-1 ; i >= 0; i--) {
		cout << lis[i] << " ";
	}
	
}
