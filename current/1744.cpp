#include <iostream>
#include <queue>

using namespace std;

priority_queue <int> ppq;
priority_queue <int,vector<int>,greater<int>> npq;
int N, a,sum = 0,cur,zcnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(a > 0)
            ppq.push(a);
        else if(a == 0)
            zcnt++;
        else
            npq.push(a);
    }
    while(!ppq.empty()){
        cur = ppq.top();
        ppq.pop();
        if(cur > 1 && !ppq.empty() && ppq.top() > 1){
            sum += cur * ppq.top();
            ppq.pop();
        }
        else{
            sum += cur;
        }
    }
    while(!npq.empty()){
        cur = npq.top();
        npq.pop();
        if(!npq.empty()){
            sum += cur * npq.top();
            npq.pop();
        }
        else if (!zcnt){
            sum += cur;
        }  
    }
    cout << sum;
}