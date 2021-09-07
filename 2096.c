#include <stdio.h>
int min_arr[3] = { 0 };
int max_arr[3] = { 0 };
int N;
int MIN(int a, int b) {
	return a < b ? a : b;
}

int MAX(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		int a, b, c, t0 = min_arr[0],t1 = min_arr[1],t2= min_arr[2];
		scanf("%d %d %d", &a, &b, &c);
		min_arr[0] = a + MIN(t0,t1);
		min_arr[1] = b + MIN(MIN(t0,t1),t2);
		min_arr[2] = c + MIN(t1,t2);
		t0 = max_arr[0]; t1 = max_arr[1]; t2 = max_arr[2];
		max_arr[0] = a + MAX(t0, t1);
		max_arr[1] = b + MAX(MAX(t0, t1), t2);
		max_arr[2] = c + MAX(t1, t2);
	}

	printf("%d %d", MAX(MAX(max_arr[0], max_arr[1]), max_arr[2]) , MIN(MIN(min_arr[0], min_arr[1]), min_arr[2]));

	return 0;
}
