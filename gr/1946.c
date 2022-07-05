#include <stdio.h>
int score[100001];
int arr[100001] = { 0 };
int flag, num;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a , &b);
			score[a] = b;
			if (b == 1)
				flag = a;
			
		}
		
		num = 1;
		
		int flag2 = score[1];
		for (int i = 2; i <= flag; i++) {
			if (score[i] < flag2) {
				num++;
				flag2 = score[i];
			}
		}
		
		printf("%d\n", num);
	}
}
