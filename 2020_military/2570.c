#include <stdio.h>
#include <stdlib.h>
int n,idx1,idx2;
int arr[100001] = { 0 };
int min = 2000000000;
int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;

	if (*(int*)a > *(int*)b)
		return 1;

	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), compare);
	
	int s = 0, e = n - 1;
	while (s < e) {
		int sum = arr[s] + arr[e];
		if (abs(sum) < min) {
			min = abs(sum);
			idx1 = s;
			idx2 = e;
		}

		if (sum < 0)
			s++;
		else
			e--;
	}
	printf("%d %d", arr[idx1], arr[idx2]);


}
