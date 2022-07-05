#include <stdio.h>

int n;
int arr[1001] ={0};
int dp[1001] ={0};

int max (int a, int b){
	return a>b ? a : b; 
}

int f(){
	int result =0;
	for(int i=0; i < n; i++){
		dp[i] = arr[i];
		for(int j= 0 ; j<n ;j++){
			if(arr[i] > arr[j] && dp[i] < dp[j]+arr[i])
				dp[i] = dp[j]+arr[i]; 
		}
		result = max(result,dp[i]);
	}
	return result;
}

int main(void) {
	
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	printf("%d",f());
	
	return 0;
}
