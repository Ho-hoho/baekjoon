#include <stdio.h>
#define INF 999999;
int dp[1000001] = { 0 };
int v[1000001] = { 0 };
int ans[1000001] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = n; i > 0; i--)
		dp[i] = INF;
	dp[n] = 0;
	for (int i = n; i > 0; i--) {
		if (dp[i - 1] > dp[i] + 1) {
			dp[i - 1] = dp[i] + 1;
			v[i - 1] = i;
		}
		if (i % 3 == 0)
			if (dp[i / 3] > dp[i] + 1) {
				dp[i / 3] = dp[i] + 1;
				v[i / 3] = i;
			}
		if (i % 2 == 0)
			if (dp[i / 2] > dp[i] + 1) {
				dp[i / 2] = dp[i] + 1;
				v[i / 2] = i;
			}
	}
	printf("%d\n", dp[1]);
	int times = dp[1];
	int way = 1;
	for (int i = 0; i <= times; i++) {
		ans[times - i] = way;
		way = v[way];
	}
	for (int i = 0; i <= times; i++) {
		printf("%d ", ans[i]);		
	}

}
