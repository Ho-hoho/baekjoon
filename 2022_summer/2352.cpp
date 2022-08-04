#include <iostream>
#include <algorithm>
#include <stack>

#define MAX 40001
using namespace std;

int N,len=0;
int arr[MAX], dp[MAX];
stack<int> ans;

int main() {
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
	cout << len << "\n";
	return 0;
}
