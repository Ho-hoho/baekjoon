#include <stdio.h>

int d, k;
int a[31] = { 0 };
int b[31] = { 0 };
int main() {
	scanf("%d %d", &d, &k);
	a[3] = 1;b[3] = 1;a[4] = 1;	b[4] = 2;
	for (int i = 5; i <= d; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	//printf("aexp = %d bexp=%d\n", a[d], b[d]);
	int tmp = k / a[d];
	int flag = 0;
	for (int i = tmp; i >= 0; i--) {
		for (int j = i+1; ; j++) {
			if (a[d] * i + b[d] * j > k)
				break;
			else if (a[d] * i + b[d] * j == k ) {
				printf("%d\n%d\n", i, j);
				flag = 1;
			}
		}
		if (flag)
			break;
	}
	return 0;
}
