#include <iostream>
#include <queue>
using namespace std;

int W,H,lv,ans = 0;
int arr[501];
int main (){
    cin >> H >> W;
    for(int i = 0;i < W;i++)
        cin >> arr[i];
    for(int lv = H; lv > 0 ; lv--){
        queue <int> q;
        for(int i = 0 ; i < W; i++){
            if(arr[i] >= lv)
                q.push(i);
        }
        while(q.size() > 1){
            int s = q.front(); q.pop();
            int e = q.front();
            ans += e - s - 1;
            
        }
    }
    cout << ans;
}