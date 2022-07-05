#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[100];

long long f (int c ){
	if(c == 0) return 0;
	if(c == 1) return 1;
	
	if(arr[c] != -1 ) return arr[c];
	
	arr[c] = f(c-1) + f(c-2);
	return arr[c];
	
}

int main() {
	int N ;
	scanf("%d", &N);
	
	fill(arr,arr+100, -1);
	printf("%lld\n",f(N));
	
	return 0;
}
