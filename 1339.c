#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[27] = { 0 };
int cmp[27] = { 0 };
int n, len = 0;;
char voc[10];

int compare(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b)
		return 1;

	if (*(int*)a > *(int*)b)
		return -1;

	return 0;
}

int main() {

	scanf("%d", &n);
	while (n--) {
		scanf("%s", &voc);
		int times = 1;
		for (int i = strlen(voc) - 1; i >= 0;i--) {
			//printf("%d", voc[i]);
			num[(voc[i]-65)] += times;
			times *= 10;
		}
		
	}
	for (int i = 0; i <= 26; i++) {
		cmp[i] = num[i];
		if (cmp[i] != 0)
			len++;
	}
	
	int ans=0;
	int digit = 9;
	qsort(cmp, 27, sizeof(int), compare);
	/*
	for (int i = 0; i < 26; i++)
		printf("%d ", num[i]);
	printf("\n");
	for (int i = 0; i < 26; i++)
		printf("%d ", cmp[i]);
	printf("\n");
	*/
	for (int i = 0; i < len; i++) {
		for (int j = 0; i <= 26;j++) {
			if (cmp[i] == num[j]) {
				ans += cmp[i] * digit;
				num[j] = 0;
				digit--;
				break;
			}
			
		}
	}
	printf("%d\n", ans);

	/*
	int c;
	c = 'A';
	printf("%d", c);
	*/
	//printf("%d", strlen(voc));
}
