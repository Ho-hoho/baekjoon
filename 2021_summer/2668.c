#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[101] = { 0 };
int ans[1001] = { 0 };
int v[101] = { 0 };
int N,idx=0;
int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return -1;

	if (*(int*)a > *(int*)b)
		return 1;

	return 0;
}
int init() {
	for (int i = 0; i <= N; i++) {
		v[i] = 0;
	}
	return 0;
}
int dfs(int i,int start) {
	if (v[i]) {
		if (i == start) {
			for (int i = 1; i <= N; i++) {
				if (v[i] == 1) {
					ans[i] = 1;
				}
			}
		}
		return 0;
	}
	else {
		v[i] = 1;
		dfs(arr[i], start);
	}
	return 0;

}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++) {
		init();
		dfs(i,i);
	}
	int ans_num = 0;
	for (int i = 1; i <= N; i++) {
		if (ans[i] == 1) {
			ans_num++;
		}
		
	}
	printf("%d\n", ans_num);
	for (int i = 1; i <= N; i++) {
		if (ans[i] == 1) {
			printf("%d\n", i);
		}

	}
	return 0;
}
