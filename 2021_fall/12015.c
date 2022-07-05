#include <stdio.h>
int arr[1000001] = { 0 };
int lis[1000001] = { 0 };
int N;

int lower_bound(int s, int e, int target) {
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (lis[mid] < target) {
			s = mid + 1;
		}
		else
			e = mid;
	}
	return e;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int i = 0, j = 0;
	lis[i] = arr[i];
	i++;
	while (i < N) {
		if (arr[i] > lis[j]) {
			lis[j + 1] = arr[i];
			j++;
		}
		else {
			int ans = lower_bound(0, j, arr[i]);
			lis[ans] = arr[i];
		}
		i++;
	}
	printf("%d", j + 1);

}
