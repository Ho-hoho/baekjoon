#include <stdio.h>

long long dp [101][10]={0};

long long stair(int n, int k){
	if(n==1){
			dp[n][k] =1;
			return 1;	
	}
	if(dp[n][k] != 0) return dp[n][k]%1000000000;
	int result;
	
	if(k==0) 
		dp[n][k] = stair(n-1,k+1)%1000000000;
	else if(k==9)
		dp[n][k] = stair(n-1,k-1)%1000000000;
	else
		dp[n][k] = (stair(n-1, k+1)+stair(n-1,k-1))%1000000000;
	
	return dp[n][k];
}

int main(void) {
	int n;
	long long sum=0;
	scanf("%d",&n);
	
	for(int i=1;i<10;i++)
		dp[1][i] = 1;
	stair(n,0);	
	
	for(int i=1; i<10 ;i++){
		//sum = (sum+stair(n,i))%1000000000;
		sum += stair(n,i)%1000000000;
	}
	
/*
	for(int i=1 ; i <= n; i++){
		for(int j=0; j < 10; j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
*/
	printf("%lld",sum%1000000000);
	return 0;
}
