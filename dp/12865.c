#include <stdio.h>

int weight[101] ={0};
int value[101] ={0};
int dp[100001] ={0};
int n=0,k=0;
int max(int a,int b){
	return a>b ? a : b;
}

int best(int c){
	if(c <= 0) return 0;
	if(dp[c] != 0) return dp[c];
	
	for(int i=0; i<n ;i++){
		if(c >= weight[i]){
			//printf("i=%d weight[i] = %d value[i] = %d dp[%d]=%d\n",i,weight[i],value[i],c,dp[c]);
			dp[c] = max(dp[c],best(c-weight[i])+value[i]);
		}
	}
	return dp[c];
}

int main (){
	
	scanf("%d %d", &n,&k);
	for(int i=0; i<n;i++){
		scanf("%d %d",&weight[i],&value[i]);
	}
	printf("%d",best(k));
/*	
	for(int i=0 ; i <=k;i++){
		printf("%d ",dp[i]);
	}
*/
	return 0;
}
