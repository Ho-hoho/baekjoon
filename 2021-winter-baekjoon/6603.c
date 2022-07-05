#include <iostream>

using namespace std;
int k;
int S[13];

void solve(int turn,int chosen,int arr[]) {
	
	if (chosen == 6 ) {
		for (int i = 0; i < 6; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	else if (turn == k)
		return;
	arr[chosen] = S[turn];
	solve(turn + 1, chosen + 1, arr);
	solve(turn + 1, chosen, arr);
	
}

int main() {
	int arr[13] = { 0 };
	while (1) {
		scanf("%d", &k);
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
			scanf("%d", &S[i]);	
		solve(0,0,arr);
		printf("\n");
	}
}
