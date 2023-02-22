#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue <int> q;
vector <int> adj[100001];
bool vis[100001];
int parent[100001];
int N,a,b;

void solve(){
    vis[1] = true;
    for(auto i : adj[1]){
        q.push(i);
        vis[i] = true;
        parent[i] = 1;
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(auto i : adj[cur]){
            if(!vis[i]){
                vis[i] = true;
                parent[i] = cur;
                q.push(i);
            }
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
    for(int i = 2; i <= N ;i++){
        cout << parent[i] << "\n";
    }
}