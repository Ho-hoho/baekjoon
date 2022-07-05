#include <stdio.h>

int arr[1001] ={0};
int d[1001] ={0};
int w[1001] ={0};
int max (int a, int b){
	return a > b ? a : b ;
}

int main (){
	int n;
	scanf("%d",&n);

	for(int i=0; i<n;i++){
		scanf("%d %d",&d[i],&w[i]);
	}
	
	int maxidx =0;
	for(int times =0; times <n; times++){
		int i;
		int maxw =0;
		for (i=0; i<n ;i++){
			if(maxw < w[i]){
				maxw = w[i];
				maxidx = i;
			}
		}
		//printf("%d %d %d\n",maxidx, maxw,w[maxidx]);
		
		for(int k= d[maxidx]-1 ;k >= 0; k--){
			//printf("here\n");
			if (w[maxidx] > arr[k] ){
				arr[k] = w[maxidx];
				//printf("%d ",arr[k]);
				break;
			}
		}
		d[maxidx]= 0;
		w[maxidx]=0;
		//printf("%d clear\n",maxidx);
		maxidx =0;
	}
	int sum =0;
	
	//for(int i=0;i<30;i++)
	//	printf("%d ", arr[i] );
	
	
	for(int i=0;i<1001;i++)
		sum += arr[i];
		
	printf("%d",sum);
}
