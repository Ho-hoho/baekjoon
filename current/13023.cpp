#include <iostream>
#include <vector>

using namespace std;
int N,M,a,b;
vector <int> adj[2001];
bool vis[2001],flag;
void dfs(int cur, int n){
    if(!flag){
        if(n == 5){
            flag = true;
            return;
        }
        vis[cur] = true;
        for(int i = 0 ; i < adj[cur].size();i++){
            if(!vis[adj[cur][i]])
                dfs(adj[cur][i],n+1);
        }
        vis[cur] = false;
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < M ;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < adj[i].size();j++){
            if(!flag && !vis[adj[i][j]])
                dfs(adj[i][j],1);
        }
        if(flag) break;
    }
    if(flag) cout << 1;
    else cout << 0;
}