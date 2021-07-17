#include <stdio.h>
#define INF 999

int M[7][7];
int P[7][7];
int D[7] = {5,2,3,4,6,7,8};

int minimum(int d, int i, int j){
	int minVal = INF;
	int minK =0;
	for(int k= i; k< j;k++){
		int value = M[i][k] + M[k+1][j];
		value += D[i-1] * D[k] * D[j];
		if(value < minVal){
			minVal =value;
			minK = k;
		}
	}
	M[i][j] = minVal;
	P[i][j] = minK;
	return 0;
}
int minmult(int d){
	int n =d-1;
	for(int i=1;i<=n;i++)
		M[i][i] = 0;
	for(int dig=1; dig < n;dig++){
		for(int i=1; i < n-dig+1;i++){
			minimum(d,i,i+dig);
		}
	}
	return 0;
}

int order(int i,int j){
	if(i==j){
		printf("A%d",i);
	}
	else{
		int k= P[i][j];
		printf("(");
		order(i,k);
		order(k+1,j);
		printf(")");
	}
	
}

int main(void) {
	int d =7;	
	for(int i=0;i<d;i++)
		for(int j=0; j<d;j++){
			M[i][j] = -1;
			P[i][j] = -1;
		}
	minmult(d);
	printf("M=\n");
	for(int i=1;i<d;i++){
		for(int j=1;j<d;j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("P=\n");
	for(int i=1;i<d;i++){
		for(int j=1;j<d;j++){
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}	
	printf("minimum =");
	order(1,d-1);
	
	
	return 0;
}
