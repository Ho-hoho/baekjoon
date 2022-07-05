#include <stdio.h>

long long arr[1001];

long long f(int c){
	if(c == 1 ) return 1;
	if(c == 2 ) return 3;
	if(arr[c] != -1) return arr[c];
	
	
	arr[c] = (2*f(c-2) + f(c-1))%10007;
	return arr[c];
}

int main(void) {
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i <= n ; i++)
		arr[i] = -1;
	
		
	printf("%lld",f(n) );
	return 0;
}
