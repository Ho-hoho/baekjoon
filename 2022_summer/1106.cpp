#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int c, n;
pair <int, int> arr[21];
int dp[100001] = {0};

int main() {
	cin >> c >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second; // first : cost / second : client
	

	for (int i = 0; i < n; i++) {
		for (int j = arr[i].first; j < 100001; j++) {
			dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
		}
	}

	for (int i = 0; i < 100001; i++) {
		if (dp[i] >= c) {
			cout << i;
			break;
		}
	}

	return 0;
}
