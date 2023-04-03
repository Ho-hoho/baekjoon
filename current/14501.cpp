#include <iostream>

using namespace std;
int n,ans = 0;
int t[20];
int p[20];

void dfs(int day, int cnt){
    if(ans < cnt) ans = cnt;
    if(day > n) return;

    if(day + 1 <= n) 
        dfs(day + 1, cnt);
    if(day + t[day] - 1<= n) 
        dfs(day + t[day] , cnt + p[day]);
}

int main (){
    cin >> n;
    for(int i = 1 ; i <= n ;i ++){
        cin >> t[i] >> p[i];
    }
    dfs(1,0);
    cout << ans;
}