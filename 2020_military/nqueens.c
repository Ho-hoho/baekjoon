#include <stdio.h>
#include <stdlib.h>
int n = 4;
int col[5] = { 0 };

int promising(int i) {
	int k = 1;
	int flag = 1;
	while (k < i && flag) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == (i - k))
			flag = 0;
		k++;
	}
	return flag;
}

int n_queens(int i) {
	if (promising(i)) {
		if (i == n) {
			for (int idx = 1; idx <= n ; idx++) {
				printf("%d", col[idx]);
			}
			printf("\n");
		}
		else {
			for (int idx = 1; idx <= n; idx++) {
				col[i + 1] = idx;
				n_queens(i + 1);
			}
		}
			
	}
	return 0;
}

int main() {
	
	n_queens(0);
	
}
