#include <stdio.h>

int a[10001] = {0};
int b[10001] = {0};
int c[10001] = {0};
int ans;
int main(void) {
	int n,k,d;
	scanf("%d %d %d", &n, &k, &d);
	for(int i=0; i<k; i++){
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
	long long low =1, high ;
	high = n;
	long long mid = 0;

	
	while(low <= high){
		int result=0;
		//printf("%d %d\n", low ,high);
		mid = (low + high) / 2 ;
		for(int i=0 ;i<k;i++){
			if( mid < a[i])
				continue;
			if (mid > b[i]){
				result += ((b[i]-a[i]) / c[i]) + 1;
			}
			else{
				result += ((mid -a[i]) / c[i]) + 1;
			}
		}
		if(result == d){
				ans = mid;
				break;
			}
		else if(result > d){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
			
	}
	
	printf("%d", ans);
	return 0;
}
