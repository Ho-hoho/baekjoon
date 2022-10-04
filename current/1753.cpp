#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;
int v,e,k;
int dis[20001];
vector < pair<int,int> > adj[20001];

void solve(){
    dis[k] = 0;
    priority_queue < pair<int, int> > pq;
    pq.push(make_pair(0,k));
    while(!pq.empty()){
        int cur = pq.top().second;
        int curdis = -pq.top().first;
        pq.pop();
        if(curdis > dis[cur])
            continue;
        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].second;
            int nextdis = curdis + adj[cur][i].first;
            if(dis[next] > nextdis){
                dis[next] = nextdis;
                pq.push(make_pair(-nextdis, next));
            }
        }
    }
}

int main (){
    int a, b, c;
    cin >> v >> e >> k;   
    for(int i = 1; i<= v; i++)
        dis[i] = INF;
    for(int i = 0 ; i < e ; i++){
        cin >> a >> b >> c;
        auto it = find_if(adj[a].begin(), adj[a].end(),
        [&b](const pair<int,int>& elem){return elem.second == b;});
        if(it == adj[a].end())
            adj[a].push_back(make_pair(c,b));
        else{
            if(it->first > c)
                it->first = c;
        }
    }
    solve();
    for(int i = 1; i <= v; i++){
        if(dis[i] != INF)
            cout << dis[i] << "\n";
        else
            cout << "INF\n";
    }
    
}