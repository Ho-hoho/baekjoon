#include <stdio.h>
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[10][10] = { 0 };
int org[10][10] = { 0 };
int n, m;

typedef struct virus {
	int x, y;
}Virus;
int MAX(int a, int b) {
	return a > b ? a : b;
}
Virus virus[64];
Virus nonvi[64];
int virus_num = 0, nonvi_num = 0;

int count_safe() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0)
				ans++;
		}
	}
	return ans;
}
int restore() {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			//hard copy?
			//int tmp;
			//tmp = org[i][j];
			//arr[i][j] = tmp;
			//soft copy??
			arr[i][j] = org[i][j];
		}
	}
	return 0;
}
int dis(int y, int x) {
	
	if (arr[y][x] == 0)
		arr[y][x] = 2;
	for (int k = 0; k < 4; k++) {
		int newy = y + dy[k];
		int newx = x + dx[k];
		if (!arr[newy][newx])
			dis(newy, newx);
	}
	return 0;
}
int make_wall() {
	int result = 0;
	for (int i = 0; i < nonvi_num-2; i++) {
		for (int j = i+1; j < nonvi_num-1; j++) {
			for (int k = j+1; k < nonvi_num; k++) {
				restore();	
				arr[nonvi[i].y][nonvi[i].x] = 1;
				arr[nonvi[j].y][nonvi[j].x] = 1;
				arr[nonvi[k].y][nonvi[k].x] = 1;
				for (int idx = 0; idx < virus_num; idx++) {
					dis(virus[idx].y, virus[idx].x);
				}
				result = MAX(result,count_safe());
				
			}
		}
	}
	return result;
}

int print_arr() {
	
	for (int i = 0; i <= n+1 ; i++) {
		for (int j = 0; j <= m+1; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n+1; i++) {
		arr[i][0] = 3;
		arr[i][m + 1] = 3;
		org[i][0] = 3;
		org[i][m + 1] = 3;
	}
	for (int i = 0; i <= m+1; i++) {
		arr[0][i] = 3;
		arr[n+1][i] = 3;
		org[0][i] = 3;
		org[n + 1][i] = 3;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			org[i][j] = arr[i][j];
			if (arr[i][j] == 2) {
				virus[virus_num].y = i;
				virus[virus_num++].x= j;
			}
			else if (arr[i][j] == 0) {
				nonvi[nonvi_num].y = i;
				nonvi[nonvi_num++].x = j;
			}
		}
	}
	
	printf("%d",make_wall());
}
