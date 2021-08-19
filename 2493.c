#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Set {
	int h;
	int idx;
}SET;
SET arr[500010] = { 0 };
SET stack[500010] = { 0 };
int ans[500010] = { 0 };
int n;

int main() {
	scanf("%d", &n);
	int rear = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i].h);
		arr[i].idx = i;
	}
	for (int i = n; i >= 1; i--) {
		int tmp;
		for (int j = rear; j > 0; j--) {
			if (arr[i].h < stack[j].h) {
				break;
			}
			else {
				ans[stack[j].idx] = arr[i].idx;
				rear -- ;
			}
		}
		rear++;
		stack[rear] = arr[i];
		
		
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
}
