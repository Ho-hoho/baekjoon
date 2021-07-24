#include <stdio.h>

int N;
int RGB[1001][3] = { 0, };
int result[1001][3] = { 0, };

int min(int a, int b) {
    return (a < b ? a : b);
}

int dp() {
    int ans = 1000005;
    for (int k = 0; k < 3; k++) {
        result[0][0] = 1000005;
        result[0][1] = 1000005;
        result[0][2] = 1000005;
        result[0][k] = RGB[0][k];

        for (int i = 1; i < N; i++) {
            result[i][0] = min(result[i - 1][1], result[i - 1][2]) + RGB[i][0];
            result[i][1] = min(result[i - 1][0], result[i - 1][2]) + RGB[i][1];
            result[i][2] = min(result[i - 1][1], result[i - 1][0]) + RGB[i][2];
        }
       //printf("ans = %d %d %d\n", result[N - 1][0], result[N - 1][1], result[N - 1][2]);
        for (int i = 0; i < 3; i++) {
            if (i == k) 
                continue;
            ans = min(ans, result[N-1][i]);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N ; i++)
        scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
    
    printf("%d\n",dp());

    return 0;
}
