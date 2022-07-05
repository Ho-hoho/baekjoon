#include <iostream>
#include <cstring>

using namespace std;

int N, sum = 0;;
int dp[31] = { 0 };

int main() {
	cin >> N;
	memset(dp, 0, sizeof(dp));
	dp[2] = 3; 
	for (int i = 4; i <= 30; i += 2) {
		dp[i] += 2;
		dp[i] += 3 * dp[i - 2];
		for(int idx = 4 ; idx <= i;idx+=2 )
			dp[i] += 2 * dp[i - idx] ;
	}
	cout << dp[N] << "\n";	
	return 0;
}
