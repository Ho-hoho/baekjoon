#include <stdio.h>
#include <stdlib.h>
int N, M;
int get[10] = { 0 };
int arr[10] = { 0 };
int visited[10] = { 0 };

int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;

	if (*(int*)a > *(int*)b)
		return 1;

	return 0;
}

int promising(int num, int count) {
	if (num <= N && count <= M)
		return 1;
	else return 0;
}

int getarr(int num, int count) {
	if (promising(num, count)) {
		if (count == M) {
			for (int idx = 1; idx <= M; idx++) {
				printf("%d ", arr[idx]);
			}
			printf("\n");
		}
		else {
			for (int i = 1; i <= N; i++) {
				if (!visited[i] && get[i] > arr[count]) {
					visited[i] = 1;
					arr[count + 1] = get[i];
					getarr(num + 1, count + 1);
					visited[i] = 0;
				}
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &get[i]);
	}
	get[0] = 0;
	qsort(get, N + 1, sizeof(int), compare);

	getarr(0, 0);

	return 0;
}
