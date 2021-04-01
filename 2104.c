#include <stdio.h>

int A[100010] ={0};
int n =0;

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

long long sol(int s, int e){
	if (s == e ) return A[s]*A[s];
	
	long long sum =0;
	long long times =0;
	
	int mid = (s+e)/2;
	long long result1 =0 , result =0;
	result = max(sol(s,mid), sol(mid+1,e)) ;
	
	int r,l;
	r=mid+1; l=mid;
	while(r-l <= e-s){
		times = 1000001; sum =0;
		for(int i=l; i<=r ;i++){
				sum += A[i];
				times = min(times , A[i]);
		}
		result1 = sum * times;
		if(A[l-1] >= A[r+1])
			l--;
		else
			r++;
		result = max(result , result1);

	}
	return result;

}

int main(void) {
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d", &A[i]);
	}
	
	printf("%d", sol(1,n));
	
	return 0;
}
