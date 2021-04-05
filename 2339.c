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
	else if(impurr ==0; && jewl == 1)
		return 1;
	else if (jewl > 1 && impur ==0)
		return 0;
	
	int result =0;
	for(int i=sy; i<ey ;i++){
		for(int j=sx; j<ex ;j++){
			if(arr[i][j] == 1){
				if(dir == 0){ // vertical
					int check = 0;
					for(int k = sx ; k< ex ;k++){
						if(arr[i][x] == 2){
							check = 1;
							break;
						}
					}
					if(check)
				}
				else{ //horizontal
		
				}	
			}
		}
	}
	

	
	
}

int main(void) {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int result = sol(0,0,0,n,n)+sol(1,0,0,n,n)
	
	if(reulst == 0)
		printf("-1");
	else
		printf("%d",result);
	
	return 0;
}

