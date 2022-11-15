#include <iostream>

using namespace std;
int dp[5001][2];
bool err = false;
int main(){
    string s;
    cin >> s;
    if(s[0] == '0')
        err = true;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1 ; i < s.length();i++){
        char cur = s[i];
        char prev = s[i - 1];
        if(cur == '0'){
            if (prev == '1' || prev == '2'){
                dp[i][0] = 0;
                dp[i][1] = dp[i - 1][0];
            }
            else{
                err = true;
                break;
            }
        }
        else{
            if(prev == '1'){
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][1] = dp[i - 1][0];
            }
            else if (prev == '2' && (cur >= '0' && cur <= '6')){
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][1] = dp[i - 1][0];
            }
            else{
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][1] = 0; 
            }
        }
        dp[i][0] %= 1000000;
        dp[i][1] %= 1000000;
    }
    int ans = dp[s.length()-1][0] + dp[s.length()-1][1];
    ans %= 1000000;
    if(err)
        cout << 0;
    else
        cout << ans;
}