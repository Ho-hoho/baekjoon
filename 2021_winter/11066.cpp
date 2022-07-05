#include <iostream>
#define MAX 100000000
using namespace std;
int N;
int dp[501][501];
int psum[501];
int arr[501];




int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			psum[i] = psum[i - 1] + arr[i];
		}
		
		

		for (int d = 1; d <= N; d++) {
			for (int i = 1; i +d<= N; i++) {
				dp[i][i + d] = MAX;
				for (int k = i; k < i + d; k++) {
					dp[i][i + d] = min(dp[i][i + d], dp[i][k] + dp[k + 1][i + d] + psum[i+d]-psum[i-1]);
				}
			}
		}
		cout << dp[1][N] << "\n";
	}

}
