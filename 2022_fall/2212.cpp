#include <iostream>
#include <algorithm>

using namespace std;

int N,K, ans = 0;
int arr[10001];
int dp[10001];

int main (){
    cin >> N >> K;
    for(int i = 0 ; i < N ;i++){
        cin >> arr[i];
    }
    sort(arr, arr+ N);
    dp[0] = 0;
    for(int i = 1; i < N ; i++){
        dp[i] = arr[i] - arr[i - 1];
    }
    sort(dp,dp + N);
    for(int i = 0 ; i < N - K + 1 ; i++)
        ans += dp[i];
    cout << ans;
}