#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 600000000
typedef pair<int, int> point;

int N,E,u,v;
vector<point> adj[801];

int dijstra(int s,int e){
    int dist[801];
    priority_queue<point,vector<point>,greater<point> > pq;
        
    for(int i = 0 ; i <= N;i++)
        dist[i] = INF;
    pq.push(make_pair(0,s));
    dist[s] = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost > dist[cur]) continue;
        for(auto i : adj[cur]){
            int next_cost = i.first;
            int next = i.second;
            //cout << "cur "<<cur << " => "<<next << " cost : " << next_cost << "\n";
            if(cost + next_cost < dist[next]){
                dist[next] = cost + next_cost;
                pq.push(make_pair(cost + next_cost,next));
            }
        }
    }
    return dist[e];
}

int main (){
    int a, b, c;
    int res;
    cin >> N >> E;
    for(int i = 0 ; i < E; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c,b));
        adj[b].push_back(make_pair(c,a));
    }
    cin >> u >> v;
    //cout << dijstra(1,u) << dijstra(u,v) << dijstra(v,N);
    res = dijstra(1,u) + dijstra(u,v) + dijstra(v,N);
    res = min(res, dijstra(1,v) + dijstra(v,u) + dijstra(u,N));
    if(res >= INF) 
        cout << -1;
    else
        cout << res;
}