#include <stdio.h>
#define arr_size 8
int List[8] = {27,10,12,20,25,13,15,22};

int merge(int* S,int low,int mid,int high){
	int U[arr_size] = {0};
	int i = low;
	int j = mid + 1;
	int idx = low ;
	while( i <= mid && j <= high){
		if(S[i] < S[j])
			U[idx++] = S[i++];
		else
			U[idx++] = S[j++];
	}	
	if(i <= mid) 
		while(i <= mid)
			U[idx++] = S[i++];
	else
		while(j <= high){
			U[idx++] = S[j++];
		}
	for(int i=low ; i <= high ;i++)
		S[i] = U[i];
	
	
}
int mergesort(int* S, int low, int high){
	
	if(low < high){
		int mid = (low + high) / 2;
		mergesort(S, low, mid);
		mergesort(S, mid+1, high);
		merge(S,low,mid,high);
	}
	return 0;
}

int main(void) {
	printf("List =");
	for(int i=0; i< arr_size ;i++){
		printf("%d ",List[i]);
	}
	printf("\nMergeSort\nList =");
	mergesort(List,0,arr_size-1);
	for(int i=0; i< arr_size ;i++){
		printf("%d ",List[i]);
	}
	
	return 0;
}
