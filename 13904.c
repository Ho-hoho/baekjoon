#include <stdio.h>

int arr[1001] ={0};
int d[1001] ={0};
int w[1001] ={0};

int main (){
	int n;
	scanf("%d",&n);

	for(int i=0; i<n;i++){
		scanf("%d %d",&d[i],&w[i]);
	}
	
	int maxidx =0;
	for(int times =0; times <n; times++){
		int i;
		for (i=0; i<n ;i++){
			if(maxidx < w[i])
				maxidx = i;
		}
		for(int k= maxidx ;k > 0; k--)
			if (w[i] > arr[k] )
				arr[k] = w[i];
		d[i]= 0;
		w[i]=0;
		maxidx =0;
		
	}
	int sum =0;
	for(int i=0;i<n;i++)
		sum += arr[i];
		
	printf("%d",sum);
}

