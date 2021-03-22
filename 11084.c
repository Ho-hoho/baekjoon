#include <stdio.h>
long long dp[101] = {0};

int stair(int n, int k){
	if(n==0) return 0;
	if(n==1) return 1;
	
	if(k == 0 )
		return stair(n-1,k+1);
	if(k == 9)
		return stair(n-1,k-1);
	else	
		return stair(n-1,k-1)+stair(n-1,k+1);
	 
}

int main(void) {
	int n, result;
	scanf("%d",&n);
	
	int result;
	for(int i = 1; i<9;i++)
		result += stair(n,9);
	
	return 0;
}
