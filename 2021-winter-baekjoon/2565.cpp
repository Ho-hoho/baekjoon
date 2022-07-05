#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> arr;
int N,ans = 0;
int dp[101] ;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) {
		dp[i]=1;
		for (int j = 0; j < i; j++) {
			if (arr[i].second > arr[j].second ) {
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << N-ans;

}
