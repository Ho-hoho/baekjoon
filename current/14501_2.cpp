#include <iostream>
#define MAX(a,b) (a > b ? a : b)

using namespace std;

int N;
int t[20];
int p[20];
int dp[20];

int main (){
    cin >> N;
    for(int i = 1 ; i <= N ;i ++){
        cin >> t[i] >> p[i];
    }
    for(int i = N ; i > 0 ; i--){
        int deadline = t[i] + i;
        if(deadline > N + 1){
            dp[i] = dp[i + 1];
        }
        else{
            dp[i] = MAX(dp[i+1],dp[deadline] + p[i]);
        }
    }
    cout << dp[1];
    return 0;
}