#include <stdio.h>

int w[4] = { 0, 5, 10, 20 };
int p[4] = { 0, 50, 60, 140 };

int max(int a, int b) {
	return a > b ? a : b;
}
int knapsack(int i,int W) {
	if (i <= 0 || W <= 0)
		return 0;
	if (w[i] > W)
		return knapsack(i - 1,W);
	else {
		int left = knapsack(i - 1, W);
		int right = knapsack(i - 1, W - w[i]);
		return max(left, p[i] + right);
	}
}

int main() {

	printf("%d" ,knapsack(3,30));
}
