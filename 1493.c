#include <stdio.h>

long long qnt[21][2] ={0};

int main (){
	int l,w,h ;
	int n;
	scanf("%d %d %d",&l,&w,&h);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&qnt[i][0], &qnt[i][1]);
	}
	int flag =0,cnt =0;
	long long totvol = l * w * h;
	for(int k = n-1 ; k >= 0 ; k--){
		//printf("k=%d\n",k);
		long long vol = 1;
		for(int i=0; i< qnt[k][0]*3 ;i++){
			vol *= 2;
		}
		//printf("vol = %d\n",vol);
		for(int i = 0;i < qnt[k][1];i++){
			totvol -= vol;
			cnt++;
			if(totvol == 0 ){
				flag =1;
				break;
			}
			else if(totvol < 0){
				totvol += vol;
				cnt--;
				break;
			}
		}
		if(flag)
			break;
	}
	
	if(totvol == 0)
		printf("%d",cnt);
	else
		printf("-1");
	
}
