#include <stdio.h>
#include <stdlib.h>

int arr[1001] ={0};
int pipe[1001] ={0};
int compare(const void *a, const void *b){
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	
	if(num1 < num2)
		return -1;
	if(num1 > num2)
		return 1;
	return 0;
}

int main (){
	int n,l;
	scanf("%d %d", &n, &l);
	for(int i=0; i<n ;i++)
		scanf("%d", &arr[i]);
	
	qsort(arr,n,sizeof(int),compare);	
	int cnt =0;
	l = l-1;
	for(int i=0; i<n;i++){
		if(pipe[arr[i]] == 0){
			pipe[arr[i]] = 1;
			cnt++;
			for(int k=0;k<=l;k++){
				pipe[arr[i]+k] = 1;
			}
		}
	}
	
	printf("%d",cnt);
}
