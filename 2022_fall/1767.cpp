#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector <pair<int,int>> adj[10001];
int a,b,c,n;
int dis[10001] = {0};
bool vis[10001] = {0};

int dijk(int k){
    int maxdis = 0, maxidx = 0;
    dis[k] = 0;
    queue <int> q;
    q.push(k);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        vis[cur] = true;
        for(auto i : adj[cur]){
            if(!vis[i.first]){
                dis[i.first] = i.second + dis[cur];
                if(dis[i.first] > maxdis){
                    maxdis = dis[i.first];
                    maxidx = i.first;
                }
                q.push(i.first);
            }
        }
    }
    if(k == 1)
        return maxidx;
    else
        return maxdis;
}

int main (){
    int temp;

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    temp = dijk(1);
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    cout << dijk(temp);
}