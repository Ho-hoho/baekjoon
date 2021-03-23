#include <stdio.h>

int dp[1001][11] = {0};

int main (){
	int n,sum=0;
	scanf("%d", &n);
	for(int i=0;i<10;i++)
		dp[1][i] = 1;
	
	for(int i = 0; i<10;i++)
		for(int j = i ; j<10 ; j++)
			dp[i][j] += dp[i-1][j]; 
  //fix here
		
	for(int i=1 ; i <= n; i++){
		for(int j=0; j < 10; j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}	
	
	for(int i = 0 ; i<10;i++)
		sum += dp[n][i];
	
	printf("%d", sum%10007);
	
	return 0;
}
