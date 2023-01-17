#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int K,V,E,a,b;
int vis[20001];
bool flag;

vector <int> adj[20001];


void bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i : adj[cur]){
            if(vis[i] == 0){
                vis[i] = -1 * vis[cur];
                q.push(i);
            }
            else if(vis[i] == vis[cur]){
                flag = true;
                return;
            }
        }
    }
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> K;
    while(K--){
        memset(vis,0,sizeof(vis));
        flag = false;
        cin >> V >> E;
        for(int i = 1 ; i <= V; i++)
            adj[i].clear();
        for(int i = 0 ; i < E ; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i = 1; i <= V;i++){
            if(!vis[i]){
                bfs(i);
            }
            if(flag)
                break;
        }

        if(flag)
            cout << "NO\n";
        else cout << "YES\n";
    }
}