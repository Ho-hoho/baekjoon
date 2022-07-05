#include <stdio.h>

int N, M;
int arr[10] = { 0 };
int visited[10] = { 0 };

int promising(int num, int count) {
	if ( num <= N && count <= M)
		return 1;
	else return 0;
}

int getarr(int num,int count) {	
	if (promising(num,count)) {
		if (count == M) {
			for (int idx = 1; idx <= M; idx++) {
				printf("%d ", arr[idx]);				
			}
			printf("\n");
		}
		else {
			
			for (int i = 1; i <= N; i++) {
					arr[count + 1] = i;
					getarr(num+1, count + 1);
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &N, &M);
	
	getarr(0,0);

	return 0;
}
