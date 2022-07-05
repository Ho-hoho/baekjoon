#include <stdio.h>
#define LEN 7

int J[8] = { 0 };
int K[8] = { 0 };
int deadline[8] = {0,3,1,1,3,1,3,2};
int profit[8] = {0,40,35,30,25,30,15,10};

int lenk() {
	int ans=0;
	for (int i = 0; i <= LEN; i++)
		if (K[i] != 0)
			ans++;
	return ans;

}
int insertK(int j, int i) {
	for (int idx = LEN; idx >= j; idx--) {
		K[idx] = K[idx - 1];
	}

	K[j-1] = i;
	
	
	return 0;
}

int insert(int i) {
	for (int idx = 0; idx <= LEN ; idx++)
		K[idx] = J[idx];

	int j;

	
	for (j = lenk() ; J > 0; j--) {
		if (deadline[i] >= deadline[K[j-1]]) {
			j++;
			break;
		}
	}
	if (j < 1)
		j = 1;
	insertK(j, i);

	return 0;
}

int feasibleK() {

	for (int i = 1; i <=  lenk(); i++) {
		if (i > deadline[K[i-1]])
			return 0;
	}
	
	return 1;
}
int schedule() {
	int n = LEN;
	J[0] = 1;
	for (int i = 2; i <= n; i++) {
		insert(i);
		if (feasibleK()) {
			for (int i = 0; i <= LEN; i++)
				J[i] = K[i];
		}
	}

}


int main() {
	schedule();
	printf("Schedule: ");
	for (int i = 0; i <= LEN; i++) {
		if (J[i] != 0)
			printf("%d ", J[i]);
	}

	int maxprofit = 0;
	for (int job = 0; job <= LEN; job++)
		maxprofit += profit[J[job]];
	printf("\nMax Profit = %d", maxprofit);
}
