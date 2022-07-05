#include <stdio.h>
int arr[501][501] = { 0 };
int n, m;
int max(int a, int b) {
	return a > b ? a : b;
}

int getmax(int i, int j) {
	int result = 0;
	int tmp;
	if (j + 3 <= 500) { // 1
		tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
		result = max(result, tmp);
	}
	if (i+3 <= 500) { // 2
		tmp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
		result = max(result, tmp);
	}
	if (i+1 <= 500 && j+1 <= 500) { // 3
		tmp = arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1];
		result = max(result, tmp);
	}
	if (i+1 <= 500 && j+2 <= 500) { // 4
		tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
		result = max(result, tmp);
	}
	if (i - 2 >= 1 && j + 1 <= 500 ) { // 5
		tmp = arr[i][j] + arr[i-1][j] + arr[i-2][j] + arr[i-2][j+1];
		result = max(result, tmp);
	}
	if (i+2 <= 500 && j -1 >= 1 ) { // 6
		tmp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j-1];
		result = max(result, tmp);
	}
	if (i-1 >= 1 && j-2 >= 1) { // 7
		tmp = arr[i][j] + arr[i][j-1] + arr[i][j-2] + arr[i-1][j-2];
		result = max(result, tmp);
	}
	if (i-2 >= 1 && j -1 >= 1) { // 8
		tmp = arr[i][j] + arr[i-1][j] + arr[i-2][j] + arr[i-2][j-1];
		result = max(result, tmp);
	}
	if (i+1 <=500 && j-2 >= 1) { // 9
		tmp = arr[i][j] + arr[i][j-1] + arr[i][j-2] + arr[i+1][j-2];
		result = max(result, tmp);
	}
	if(i+2 <=500 && j+1 <= 500) { // 10
		tmp = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
		result = max(result, tmp);
	}
	if(i-1 >= 1 && j + 2 <= 500) { //11
		tmp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+2];
		result = max(result, tmp);
	}
	 if (i+2 <= 500 && j+1 <= 500) { //12
		tmp = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
		result = max(result, tmp);
	}
	 if (i - 2 >= 1 && j+1 <= 500) {// 13
		tmp = arr[i][j] + arr[i-1][j] + arr[i-1][j+1] + arr[i-2][j+1];
		result = max(result, tmp);
	}
	if (i+1 <=500 && j+2 <= 500) { // 14
		tmp = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
		result = max(result, tmp);
	}
	if (i+1 <=500 && j-2 >= 1) { // 15
		tmp = arr[i][j] + arr[i][j-1] + arr[i+1][j-1] + arr[i+1][j-2];
		result = max(result, tmp);
	}
	if (i + 1<= 500 && j+2 <=500) { //16
		tmp = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i][j+2];
		result = max(result, tmp);
	}
	if (i-1 >=1 && j-2>=1) { // 17
		tmp = arr[i][j] + arr[i][j-1] + arr[i][j-2] + arr[i-1][j-1];
		result = max(result, tmp);
	}
	if (i+2 <=500 && j-1 >= 1) { // 18
		tmp = arr[i][j] + arr[i+1][j] + arr[i+1][j-1] + arr[i+2][j];
		result = max(result, tmp);
	}
	if (i-2 >= 1 && j+ 1 <= 500) { // 19
		tmp = arr[i][j] + arr[i-1][j] + arr[i-2][j] + arr[i-1][j+1];
		result = max(result, tmp);
	}
	return result;
}

int main() {
	int ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int  tmpp = getmax(i, j);
			ans = max(ans, tmpp);
		}
	}
	
	printf("%d",ans);
}
