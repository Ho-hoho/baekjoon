#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
string s1, s2;
int dp[1002][1002] = { 0 };
int find(int n1,int n2) {
	if (dp[n1][n2] == 0) {
		return 0;
	}
	if (s1[n1 - 1] == s2[n2 - 1]) {
		find(n1 - 1, n2 - 1);
		cout << s1[n1 - 1];
	}
	else {
		dp[n1 - 1][n2] > dp[n1][n2 - 1] ? find(n1 - 1, n2) : find(n1 , n2-1);
	}
	return 0;
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2;
	int n1 = s1.size();
	int n2 = s2.size();
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			if (i==0||j==0) {
				dp[i][j] = 0;
			}
			else if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;

			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n1][n2] << "\n";

	find(n1, n2);
	return 0;
}
