#include <stdio.h>

int main (){
	int cnt = 1;
	while(1){
		int result =0;
		int l,p,v;
		scanf("%d %d %d",&l,&p,&v);
		if(l==0 && p==0 && v ==0)
			break;
		while(v > 0){
			if (v <= l){
				result += v;
				break;
			}
			v -= l;
			result += l;
			v = v- (p-l);
		}
		printf("Case %d: %d\n",cnt++,result);
	}
}
