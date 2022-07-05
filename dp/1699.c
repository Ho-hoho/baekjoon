#include <stdio.h>
int dp[100001] = {0};

int min (int a, int b){
	return a>b ? b : a ; 	
}

int main(void) {
	int n;
	
	scanf("%d", &n);
	
	for(int i=1; i<=n ; i++){
		dp[i] = 1000001;
	}
	for(int i=1 ; i <= n ; i++){
		for(int j=1 ; j*j <= i ; j++){
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}
	
	printf("%d",dp[n]);
	
	return 0;
}
