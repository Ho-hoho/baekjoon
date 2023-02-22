#include <iostream>


using namespace std;

string dp[101][101];
int n , m;

string add(string _s1, string _s2){
    string ret = "";
    char arr[1001];
    string s1,s2;
    if(_s1.length() > _s2.length()){
        s1 = _s2;
        s2 = _s1;
    } 
    else{
        s1 = _s1;
        s2 = _s2;
    }
    int len1 = s1.length();
    int len2 = s2.length();
    int diff = len2 - len1;
    int carry = 0;
    for(int i = len2 - 1 ; i >= 0 ; i--){
        if(i >= diff){
            arr[i] = s1[i-diff] + s2[i] - '0' + carry;
            if(arr[i] > '9'){
                arr[i] -= 10;
                carry = 1;
            }
            else
                carry = 0;
        }
        else{
            arr[i] = s2[i] + carry;
            if(arr[i] > '9'){
                arr[i] -= 10;
                carry = 1;
            }
            else carry = 0;
        }
    }
    if(carry == 1)
        ret += "1";
    for(int i = 0 ; i < len2 ;i++){
        ret += arr[i];
    }
    return ret;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    cin >> n >> m;
    
    for(int i = 1 ; i <= n ;i++){
        dp[i][0] = "1";
        dp[i][i] = "1";
    }
    if(m > n/2)
        m = n - m;
    for(int i = 2 ; i <= n ;i++){
        for(int j = 1 ; j <= i / 2;j++){
            string s = add(dp[i-1][j-1],dp[i-1][j]);
            dp[i][j] = s;
            dp[i][i - j] = s;
        }
    }
    
    cout << dp[n][m];
}