#include <stdio.h>
int n;
int a[3000][3000];
int score[3] = {0};

int sol (int y, int x ,int k){
/*	if(k == 1){
		for(int i =0; i<3;i++){
			for(int j=0;j<3;j++){
				if(a[y+i][x+j] == 0){
					//printf("%d %d %d \n",y,x, a[y][x]);
					score[0] += 1;
				}
				else if(a[y+i][x+j] == 1){
					//printf("%d %d %d \n",y,x, a[y][x]);
					score[1] += 1;
				}
				else if(a[y+i][x+j] == -1){
					//printf("%d %d %d \n",y,x, a[y][x]);
					score[2] += 1;
				}
			}
		}
		return 0;
	}
	*/
	int flag = a[y][x],yflag=0,xflag=0;
	for(int i=0;i<k;i++){
		for(int j=0; j<k;j++){
			if (a[y+i][x+j] == flag)
				continue;
			else {
				flag = 10;
				break;
				
			}
		}
	}

	if(flag == 10){
		for(int i=0; i< k ; i += (k/3)){
			for(int j=0; j < k ;j += (k/3)){
			//	printf("divide %d %d to %d\n", y+i,x+j,k/3);
				sol(y+i,x+j, k/3);
			}
		}
	}
	else{
		if(a[y][x] == 0){
			//printf("%d %d %d \n",y,x, a[y][x]);
			score[0] += 1;
		}
		else if(a[y][x] == 1){
			//printf("%d %d %d \n",y,x, a[y][x]);
			score[1] += 1;
		}
		else if(a[y][x] == -1){
			//printf("%d %d %d \n",y,x, a[y][x]);
			score[2] += 1;
		}
	}
	
	return 0;
}

int main (){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0; j<n;j++)
			scanf("%d",&a[i][j]);
	sol(0,0,n);
	
	printf("%d\n%d\n%d",score[2],score[0],score[1]);
	return 0;
}
