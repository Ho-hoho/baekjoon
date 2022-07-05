#include <stdio.h>
#include <stdlib.h>
int arr[1001][1001] = { 0,};

int main() {
	int n, m, flag2 =0;
	scanf("%d %d", &n, & m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j])
				flag2 = 1;
		}
	}
	if (!flag2) {
		printf("0\n");
		return 0;		
	}

	int k = 1;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] >= k * k && arr[i][j + 1] >= k * k && arr[i + 1][j] >= k * k && arr[i + 1][j + 1] >= k * k) {
					arr[i + 1][j + 1] = (k + 1) *(k + 1);
					flag = 1;
				}
			}
		}
		k++;
	}
	k--;
	printf("%d\n", k * k);
	return 0;
}
