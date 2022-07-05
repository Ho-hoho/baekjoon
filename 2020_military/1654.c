#include <stdio.h>

long long lan[10001] = {0};

int main(void) {
	int k,n;
	long long low =1, high =0; // low = 1 이 포인트
	scanf("%d %d", &k, &n);
	
	for(int i=0; i<k ;i++){
		scanf("%lld",&lan[i]);
		if(lan[i] > high)
			high = lan[i];
	}
	
	long long mid = 0;
	long long result = 0;
	while(low <= high){
		
		long long cnt = 0;
		mid = (low + high)/2;
		for(int i=0 ;i<k ;i++)
			cnt += lan[i]/mid ;
		
		if(cnt >= n ){
			low = mid +1;
			if(mid > result)
				result = mid;
		}
		else{
			high = mid -1;
		}
	}
	
	printf("%lld", result);
	return 0;
}
