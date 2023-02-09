#include <iostream>

using namespace std;

int N;
int dp[1001][3][2];
int sum = 0;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    for(int i = 1 ; i < N ;i++){
        dp[i+1][0][0] = (dp[i][0][0] + dp[i][1][0] + dp[i][2][0])%1000000;

        dp[i+1][0][1] = (dp[i][0][0] + dp[i][1][0] + dp[i][2][0] 
                        + dp[i][0][1] + dp[i][1][1] + dp[i][2][1])%1000000;
        dp[i+1][1][0] = dp[i][0][0];
        dp[i+1][1][1] = dp[i][0][1];
        dp[i+1][2][0] = dp[i][1][0];
        dp[i+1][2][1] = dp[i][1][1];
    }
    sum = dp[N][0][0] + dp[N][0][1] + dp[N][1][0] + dp[N][1][1] + dp[N][2][0] + dp[N][2][1];
    cout <<  sum % 1000000; 
}