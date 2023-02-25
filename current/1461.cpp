#include <iostream>
#include <queue>

using namespace std;

int N, M,a,ans;
priority_queue <int> ppq;
priority_queue <int> npq;

void solve(){
    while(!ppq.empty()){
        int temp = 0;
        temp += ppq.top(); ppq.pop();
        for(int i = 0 ; i < M - 1; i++){
            if(ppq.empty()) break;
            ppq.pop();
        }
        ans += temp * 2;
    }
    while(!npq.empty()){
        int temp = 0; 
        temp += npq.top(); npq.pop();
        for(int i = 0 ; i < M - 1; i++){
            if(npq.empty()) break;
            npq.pop();
        }
        ans += temp * 2;
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        cin >> a;
        if(a >=0 ){
            ppq.push(a);
        }
        else{
            npq.push(-a);
        }
    }
    if(ppq.empty())
        ans = -npq.top();
    else if (npq.empty())
        ans = -ppq.top();
    else if (ppq.top() > npq.top())
        ans = -ppq.top();
    else
        ans = -npq.top();
    solve();
    cout << ans;
}