#include <stdio.h>
#define INF 999;
int A[7][7];
int R[7][7];
int keys[6] = {0,10,20,30,40,50};
int P[6] = { 0,35,12,22,8,15 };

int minimum(int i, int j) {
	int minVal = INF;
	int minK = 0;
	for (int k = i; k <= j; k++) {
		int value = A[i][k - 1] + A[k + 1][j];
		for (int m = i; m <= j; m++)
			value += P[m];
		if (value < minVal) {
			minVal = value;
			minK = k;
		}
	}
	A[i][j] = minVal;
	R[i][j] = minK;
	return 0;
}
int optsearchtree(int p){
	int n = p - 1;
	for (int i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = P[i];
		R[i][i - 1] = 0;
		R[i][i] = i;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;
	for (int dig = 1; dig < n; dig++) {
		for (int i = 1; i <= n - dig; i++) {
			
			minimum(i, i+dig);
		}
	}
	return 0;
}


int main() {
	int p = 6;
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			A[i][j] = -1;
			R[i][j] = -1;
		}
	}
	optsearchtree(6);
	printf("A=\n");
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%5d",A[i][j]);
		}
		printf("\n");
	}
	printf("R=\n");
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%5d",R[i][j]);
		}
		printf("\n");
	}

}
