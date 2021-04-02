#include <stdio.h>

long long A[100010] ={0};
int n =0;

long long max(long long a, long long b){
	return a > b ? a : b;
}

long long min(long long a, long long b){
	return a < b ? a : b;
}

long long sol(int s, int e){
	if(s > e) return -1;
	if (s == e ) return A[s]*A[s];
	
	long long sum =0;
	long long times =0;
	
	int mid = (s+e)/2;
	long long result =0;
	result = max(sol(s,mid), sol(mid+1,e)) ;
	
	int r,l;
	r=mid; l=mid;
	times = A[mid]; 
	sum =A[mid];
	while(r-l < e-s){
		long long lval = l > s ? A[l-1] : -1;
		long long rval = r < e ? A[r+1] : -1;
		
		if(lval > rval){
			sum += lval;
			times = min(times , lval);
			l--;
		}
		else{
			sum += rval;
			times = min(times , rval);
			r++;
		}
		//printf("%d\n",sum*times);
		result = max(result , sum*times);

	}
	return result;

}

int main(void) {
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d", &A[i]);
	}
	
	printf("%lld", sol(1,n));
	
	return 0;
}
