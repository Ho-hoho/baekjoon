#include <stdio.h>
int N;
char arr[10001][10001] = {0};

int makeStar(int size,int y, int x){
	if(size == 3){ // threshold
		arr[y][x] = '*';
		arr[y][x+1] = '*';
		arr[y][x+2] = '*';
		arr[y+1][x] = '*';
		arr[y+1][x+2] = '*';
		arr[y+2][x] = '*';
		arr[y+2][x+1] = '*';
		arr[y+2][x+2] = '*';
	}
	else{
		size /= 3;
		int mrow1 = y + size;
		int mrow2 = y + size+size;
		int mcol1 = x + size;
		int mcol2 = x + size + size;
		
		makeStar(size,y,x); //1
		makeStar(size,y,mcol1); //2
		makeStar(size,y,mcol2);//3
		makeStar(size,mrow1,x);//4
		makeStar(size,mrow1,mcol2);//6
		makeStar(size,mrow2,x);//7
		makeStar(size,mrow2,mcol1);//8
		makeStar(size,mrow2,mcol2);//9
		
	}
	return 0;
}

int printStar(){
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
				printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		for(int j=0; j<N;j++)
			arr[i][j] = ' ';
	makeStar(N,0,0);
	printStar();
	return 0;
}
