#include <stdio.h>

int n, m;

int ssg(int n,int m) {
	if (n == 0)
		return 0;
	if (n > m)
		return ssg((n % m), m);
	else if(n == m){
		return 0;
	}
	else {
		return (ssg(n , m-n) + n);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	
	printf("%d",ssg(n, m));
	return 0;
}
