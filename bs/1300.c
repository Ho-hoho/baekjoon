#include <stdio.h>

int min (int a, int b){
	return a > b ?  b :  a;
}
int main (){
	int n,k;
	scanf("%d %d",&n,&k);
	long long low = 1, high = k;
	int result = -1;
	while (low <=high){
		int cnt =0;
		long long mid = (low + high) / 2;
		for(int i=1; i<= n;i++){
			cnt += min(mid/i,n);
		}
		if(cnt < k)
			low = mid + 1;
		else{
			result = mid;
			high = mid - 1;
		}
		
	}
	printf("%d",result);
	return 0;
}
