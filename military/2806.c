#include <stdio.h>
int A[1000000];
int B[1000000];
char s[1000001];
int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int n;
	scanf("%d\n", &n);
	scanf("%s", &s);

	if (s[0] == 'A') {
		A[0] = 0;
		B[0] = 1;
	}
	else {
		A[0] = 1;
		B[0] = 0;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == 'A') {
			A[i] = min(A[i - 1], B[i - 1] + 1);
			B[i] = min(A[i - 1] + 1, B[i - 1] + 1);
		}
		else {
			A[i] = min(A[i - 1] + 1, B[i - 1] + 1);
			B[i] = min(A[i - 1] + 1, B[i - 1] );
		}

	}
	printf("%d", A[n - 1]);

	return 0;	
}
