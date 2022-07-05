#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mat[1025][1025] = { 0 };
int sum[1025][1025] = { 0 };
int exp[100001][4] = { 0 };
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &exp[i][0], &exp[i][1], &exp[i][2], &exp[i][3]);
	}
	sum[0][0] = mat[0][0];
	for (int i = 0; i < N; i++) {
		sum[i][0] = mat[i][0];
		for (int j = 1; j < N; j++) {
			sum[i][j] = sum[i][j - 1] + mat[i][j];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j];
		}
	}
	//printf("\n");

	for (int i = 0; i < M; i++) {		
		int x1 = exp[i][0]-1;
		int x2 = exp[i][2] - 1;
		if (exp[i][0] > exp[i][2]) {
			x2 = exp[i][0] - 1;
			x1 = exp[i][2] - 1;

		}

		int y1 = exp[i][1]-1;		
		int y2 = exp[i][3]-1;
		if (exp[i][1] > exp[i][3]) {
			y2 = exp[i][1] - 1;
			y1 = exp[i][3] - 1;

		}

		int ans = sum[x2][y2] + sum[x1-1][y1-1] - sum[x2][y1-1] - sum[x1-1][y2];
		printf("%d\n", ans);
	}

/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
	/*
	printf("\n");
	for (int i = 0; i < M; i++) {
		printf("%d %d %d %d", exp[i][0], exp[i][1], exp[i][2], exp[i][3]);
		printf("\n");
	}
*/

}
