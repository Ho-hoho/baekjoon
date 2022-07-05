#include <stdio.h>

int arr[25][25] = {0};

void drawArr(int y,int x){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
}

int sol(int dir, int sx, int sy, int ex, int ey){
	int jewl =0;
	int impur=0;
	
	for(int i=sy;i<ey;i++){
		for(int j=sx;j<ex;j++){
			if(arr[i][j] == 1)
				impur++;
			else if(arr[i][j] == 2)
				jewl++;
		}
		
	}
	if(impur ==0 && jewl == 0)
		return 0;
	else if(impur ==0 && jewl == 1)
		return 1;
	else if (jewl > 1 && impur ==0)
		return 0;
	
	int result =0;
	for(int i=sy; i<ey ;i++){
		for(int j=sx; j<ex ;j++){
			if(arr[i][j] == 1){
				if(dir == 0){ // horizontal 가로
					int check = 1;
					for(int k = sx ; k< ex ;k++){
						if(arr[i][k] == 2){
							check = 0;
							break;
						}
					}
					if(check){
						result += sol(1,sx,sy,ex,i)*sol(1,sx,i+1,ex,ey);
					}
				}
				else{ //vertical 세로
					int check = 1;
					for(int k = sy ; k< ey ;k++){
						if(arr[k][j] == 2){
							check = 0;
							break;
						}
					}
					if(check){
						result += sol(0,sx,sy,j,ey)*sol(0,j+1,sy,ex,ey);
					}
				}	
			}
		}
	}
	
return result;
	
	
}

int main(void) {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int result = sol(0,0,0,n,n)+sol(1,0,0,n,n);
	
	if(result == 0)
		printf("-1");
	else
		printf("%d",result);
	
	return 0;
}
