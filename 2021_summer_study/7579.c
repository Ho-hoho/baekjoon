#include <stdio.h>

int dp[10000001] = { 0 };
int W[101] = { 0 };
int P[101] = { 0 };
#define INF 99999999;

int MIN(int a, int b) {
	return a < b ? a : b;
}
int MAX(int a, int b) {
	return a > b ? a : b;
}


int N, M, sumofW=0,sumofP=0;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &W[i]);
		sumofW += W[i];
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
		sumofP += P[i];
	}

	
	M = sumofW - M;
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= 1; j--) {
			if(W[i] <= j)
				dp[j] = MAX(dp[j], dp[j - W[i]] + P[i]);
		}
	}

	printf("%d", sumofP - dp[M]);
}
