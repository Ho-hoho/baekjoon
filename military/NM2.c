#include <stdio.h>

int N, M;
int include[10] = { 0 };

int promising(int i, int last) {
	if (i > last)
		return 1;
	else
		return 0;
}
int getarr(int i,int num,int last) {
	if (promising(i, last)) {
		if (num == M) {
			for (int idx = 1; idx <= N; idx++) {
				if (include[idx] == 1){
					printf("%d ", idx);
				}
			}
			printf("\n");
		}
		else if(i == N){
			return 0;
		}
		else {
			if (last == -1) i == 0;
			include[i + 1] = 1;
			getarr(i + 1,num+1,last+1);
			include[i + 1] = 0;
			getarr(i + 1,num,last);

		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &N, &M);
	getarr(0,0,-1);

	return 0;
}
