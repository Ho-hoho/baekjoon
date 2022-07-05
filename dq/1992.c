#include <stdio.h>
int n;
int a[3000][3000];

int sol (int y, int x ,int k){
	//printf("y=%d x=%d k=%d\n",y,x,k);
	int flag = a[y][x];
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
		printf("(");
		for(int i=0; i< k ; i += (k/2)){
			for(int j=0; j < k ;j += (k/2)){
				//printf("divide %d %d to %d\n", y+i,x+j,k/2);
				sol(y+i,x+j, k/2);
			}
		}
		printf(")");
	}
	else{
		if(a[y][x] == 0){
			//printf("%d %d %d \n",y,x, a[y][x]);
			printf("0");
			
		}
		else if(a[y][x] == 1){
			//printf("%d %d %d \n",y,x, a[y][x]);
			printf("1");
		}
	}
	
	return a[y][x];
	
}

int main (){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0; j<n;j++)
			scanf("%1d",&a[i][j]);

	sol(0,0,n);
	
	
	return 0;
}
