#include <stdio.h>

int dp[1001][11] = {0};

int main (){
	int n,sum=0;
	scanf("%d", &n);
	for(int i=0;i<10;i++)
		dp[1][i] = 1;
	
	for(int i = 1; i<=n;i++)
		for(int j = 0 ; j<10 ; j++)
			for(int k=j ; k<10 ;k++)
				dp[i][j] = (dp[i][j] + dp[i-1][k])%10007;
/*		
	for(int i=1 ; i <= n; i++){
		for(int j=0; j < 10; j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	for(int j=0; j < 10; j++)
		printf("%d ",dp[n][j]);	
*/	

	for(int i = 0 ; i<10;i++)
		sum = (sum + dp[n][i]);
	
	printf("%d", sum%10007);
	
	return 0;
}
