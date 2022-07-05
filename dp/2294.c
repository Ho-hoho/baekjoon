#include <stdio.h>

int coin[101],dp[10001] ; 

int min (int a, int b){
	return (a>b) ? b : a ;
}

int main(void) {
	int n, k;
	
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n ; i++)
		scanf("%d", &coin[i]);

	coin[0] =0;
	dp[0] = 0;
	
	for(int i=1; i<=k ; i++)
		dp[i] = 10001;
	
	for(int i=1; i<=n ; i++){
		for(int j=coin[i]; j<=k;j++){
			dp[j] = min(dp[j], dp[j-coin[i]] + 1 );
			//printf("%d\n ",dp[j]);
		}
			
	}	

	if(dp[k] == 10001)
		printf("-1");
	else printf("%d",dp[k]);
	return 0;
}
