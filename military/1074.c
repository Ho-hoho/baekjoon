#include <stdio.h>

int idx =0;
int N=0,R=0,C=0;

int Zfunc(int size,int i,int j){
	//printf("i= %d , j= %d \n",i,j);
	if(size == 1){
		if(i == R && j == C)
			printf("%d",idx);
		else 
			idx++;
	}
	else{	
		int mid = size/2;
		//printf("%d %d\n",i+mid,j+mid);
		if(R<i+mid && C<j+mid){ // 1사분면
		//	printf("Go 1\n");
			Zfunc(mid,i,j);
		}
		else if(R<i+mid && C>=j+mid){ // 2사분면
		//	printf("Go 2\n");
			idx += mid*mid;
			Zfunc(mid,i,j+mid);
		}
		else if(R>=i+mid && C<j+mid){ // 3사분면
		//	printf("Go 3\n");
			idx += mid*mid*2;
			Zfunc(mid,i+mid,j);
		}
		else{ // 4사분면
		//	printf("Go 4\n");
			idx += mid*mid*3;
			Zfunc(mid,i+mid,j+mid);
		}
	}	
	return 0;
}

int main(void) {
	scanf("%d %d %d", &N, &R, &C);
	int Nsize =1;
	for(int i=0; i< N; i++)
		Nsize *=2 ;
	Zfunc(Nsize,0,0);
	return 0;
}
