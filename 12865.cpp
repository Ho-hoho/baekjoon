#include <stdio.h>

int weight[101] ={0};
int value[101] ={0};
int dp[100001] ={0};
int n=0,k=0;
int max(int a,int b){
	return a>b ? a : b;
}

int best(){
	
	for(int i=0; i<n ;i++){
		for(int j=k; j>0;j--){
			if(j >= weight[i]){
				dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
			}
		}
	}
	
	return dp[k];
}

int main (){
	
	scanf("%d %d", &n,&k);
	for(int i=0; i<n;i++){
		scanf("%d %d",&weight[i],&value[i]);
	}
	printf("%d",best());
/*	
	for(int i=0 ; i <=k;i++){
		printf("%d ",dp[i]);
	}
*/
	return 0;
}
