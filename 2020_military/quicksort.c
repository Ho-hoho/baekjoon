#include <stdio.h>
#define arr_size 10

int List[10] = {26,5,37,1,61,11,59,15,48,19};
int swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* S ,int low,int high){
	int pivotitem = S[low];
	int i = low+1;
	int j = high;
	while(i<=j){
		while(S[i] < pivotitem)
			i++;
		while(S[j] > pivotitem)
			j--;
		
		if(i < j)
			swap(&S[i],&S[j]);
	}
	swap(&S[low],&S[j]);
	return j;
}
int Quicksort (int* S, int low, int high){
	if(low < high){
		int pivotpoint = partition(S, low, high);
		Quicksort(S, low, pivotpoint-1);
		Quicksort(S, pivotpoint+1, high);
	}
}

int main(){
	printf("List = ");
	for(int i =0; i<arr_size ;i++){
		printf("%d ",List[i]);
	}
	printf("\nQuickSort\n List =");
	Quicksort(List,0,arr_size-1);
	for(int i =0; i<arr_size ;i++){
		printf("%d ",List[i]);
	}
	
}
