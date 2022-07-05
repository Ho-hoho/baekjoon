#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int N, ans =-1,answ=-1;
int board[20][20];
int MAX(int a, int b) {
	return a > b ? a : b;
}
int promising(int y,int x) {
	int flag = 1,k=0;
	int syl = y, sxl = x, syr = y, sxr = x;
	if (board[y][x] == 0)
		return 0;
	while (syl > 1 && sxl > 1) {
		syl--; sxl--;
	}
	while (syr > 1 && sxr < N) {
		syr--; sxr++;
	}
	//printf("yl = %d xl =%d yr=%d xr=%d\n", syl, sxl, syr, sxr);
	while(syl+k <= N && sxl+k<=N && flag){
		if(syl+k != y && sxl+k !=x)
			if (board[syl + k][sxl + k] == 2) {
				//printf("%d %d cant y=%d x=%d\n",x,y,syl + k,sxl + k);
				flag = 0;
			}
		k++;
	}
	k = 0;
	while (syr + k <= N && sxr- k > 0 && flag) {
		if (syr + k != y && sxr - k != x)
			if (board[syr + k][sxr - k] == 2) {
				//printf("cant y=%d x=%d\n", syl + k, sxl - k);
				flag = 0;
			}
		k++;
	}
	return flag;
}
int n_bishops_black(int y,int x,int tmp) {
	//printf("black y= %d x= %d,tmp = %d\n", y, x, tmp);

	if (y == N && x == N - 1) {
		if (promising(y, x))
			tmp += 1;
		ans = MAX(ans, tmp);
		return 0;
	}
	else if (y == N && x == N) {
		if (promising(y, x))
			tmp += 1;
		ans = MAX(ans, tmp);
		return 0;
	}
	if (promising(y, x)) {
		
					
			board[y][x] = 2;
			if(x+2 <= N)
				n_bishops_black(y, x + 2, tmp +1);
			else {
				if((y+1) %2 == 1)
					n_bishops_black(y + 1, 1, tmp + 1);
				else
					n_bishops_black(y + 1, 2, tmp + 1);
			}
			board[y][x] = 1;
			if (x + 2 <= N)
				n_bishops_black(y, x + 2, tmp );
			else if (y+1<= N){
				if ((y + 1) % 2 == 1)
					n_bishops_black(y + 1, 1, tmp );
				else
					n_bishops_black(y + 1, 2, tmp );
			}

		

	}
	else if(y <= N){
		if (x + 2 <= N)
			n_bishops_black(y, x + 2, tmp);
		else {
			if ((y + 1) % 2 == 1)
				n_bishops_black(y + 1, 1, tmp);
			else
				n_bishops_black(y + 1, 2, tmp);
		}
	}

	return 0;
}
int n_bishops_white(int y, int x, int tmp) {
	//printf("white y= %d x= %d tmp = %d\n", y, x,tmp);
	if (y == N && x == N - 1) {
		if (promising(y, x))
			tmp += 1;
		answ = MAX(answ, tmp);
		return 0;
	}
	else if (y == N && x == N) {
		if (promising(y, x))
			tmp += 1;
		answ = MAX(answ, tmp);
		return 0;
	}
	if (promising(y, x)) {
		
			//printf("white y= %d x= %d\n", y, x);
			board[y][x] = 2;
			if (x + 2 <= N)
				n_bishops_white(y, x + 2, tmp + 1);
			else {
				if ((y + 1) % 2 == 1)
					n_bishops_white(y + 1, 2, tmp + 1);
				else
					n_bishops_white(y + 1, 1, tmp + 1);
			}
			board[y][x] = 1;
			if (x + 2 <= N)
				n_bishops_white(y, x + 2, tmp);
			else if (y + 1 <= N) {
				if ((y + 1) % 2 == 1)
					n_bishops_white(y + 1, 2, tmp);
				else
					n_bishops_white(y + 1, 1, tmp);
			}

		

	}
	else if(y <= N){
		if (x + 2 <= N)
			n_bishops_white(y, x + 2, tmp);
		else {
			if ((y + 1) % 2 == 1)
				n_bishops_white(y + 1, 2, tmp);
			else
				n_bishops_white(y + 1, 1, tmp);
		}
	}
	return 0;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	//printf("prom? = %d\n", promising(5, 1));
	n_bishops_black(1, 1, 0);
	if (N != 1)
		n_bishops_white(1, 2, 0);
	else
		answ = 0;
	printf("%d", ans+answ);

}
