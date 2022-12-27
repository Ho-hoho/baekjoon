#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> point;

int arr[201];
int N , M, a, b;
bool vis[201];
queue <point> q;
int main (){
    cin >> N >> M;
    for(int i = 0 ; i < 201 ; i++)
        arr[i] = i;
    for(int i = 0 ; i < N + M ; i++){
        cin >> a >> b;
        arr[a] = b;
    }
    q.push(make_pair(1,0));
    while(!q.empty()){
        point cur = q.front(); q.pop();
        for(int i = 1 ; i <= 6; i++){
            if(arr[cur.first + i] == 100){
                cout << cur.second + 1;
                q = queue <point>();
                break;
            }
            if(!vis[arr[cur.first + i]]){
                q.push(make_pair(arr[cur.first + i],cur.second + 1));
                vis[arr[cur.first + i]] = true;
            }
        }
    }
}