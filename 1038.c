#include <stdio.h>
int n;
long long i;

int promising(long long num) {
	long long l,h;
	long long dig = 1;
	if (num >= 0 && num < 10)
		return 1;
	while (num > 10) {
		l = num % 10;
		num = num / 10;
		dig *= 10;
		h = num % 10;
		if (h > l)
			continue;
		else {
			i = ((num+1) * dig)-1;
			return 0;
		}
	}
	return 1;
}

int main() {
	int count=0,over=0;
	scanf("%d", &n);
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	for (i = 1; i<= 9876543210; i++) {
		if (promising(i)) {
			count++;
			if (count == n) {
				printf("%lld", i);
				over = 1;
				break;
			}
		}
	}
	if (over == 0)
		printf("-1");
	return 0;
	
}
