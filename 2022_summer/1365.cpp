#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 1000010

using namespace std;

int N;
int arr[MAX], dp[MAX], memo[MAX];
stack <int> ans;
int len = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	dp[len++] = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] > dp[len - 1]) {
			dp[len++] = arr[i];
		}
		else {
			int* iter = lower_bound(dp, dp + len, arr[i]);
			*iter = arr[i];
		}
	}
	cout << N - len;
	return 0;
}
