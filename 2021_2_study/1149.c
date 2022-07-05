#include <stdio.h>

int arr[3] = { 0 };
int N;
int MIN(int a, int b) {
	return a < b ? a : b;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b, c, t0 = arr[0], t1 = arr[1], t2 = arr[2];
		scanf("%d %d %d", &a, &b, &c);
		arr[0] = a + MIN(t1, t2);
		arr[1] = b + MIN(t0, t2);
		arr[2] = c + MIN(t0, t1);
	}
	printf("%d", MIN(arr[0], MIN(arr[1], arr[2])));

	return 0;
}
