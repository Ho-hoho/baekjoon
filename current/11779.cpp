#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define INF 987654321;
using namespace std;

typedef pair<int,int> point;
int N, M, s, e, a, b, c;
int cost;
vector <point> adj[1001];
int vis[1001] = {0};
int dist[1001] ;
priority_queue <point,vector<point>,greater<point>> q;
stack <int> ans;

void bfs(){
    for(int i = 1 ; i <= N;i++)
        dist[i] = INF;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int curdis = q.top().first;
        int curpos = q.top().second;
        q.pop();
        
        if(curpos == e){
            cost = dist[e];
            return;
        }
        for(auto i : adj[curpos]){
            int nextdis = curdis + i.second;
            int nextpos = i.first;
            if(nextdis < dist[nextpos]){
                vis[nextpos] = curpos;
                dist[nextpos] = nextdis;
                q.push(make_pair(nextdis,nextpos));
            }
        }
    }
}

void backtrack(){
    int cur = e;
    ans.push(e);
    while(cur != s){
        cur = vis[cur];
        ans.push(cur);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i  = 0 ; i < M ;i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
    }

    cin >> s >> e;
    bfs();
    backtrack();
    cout << cost << "\n" << ans.size() << "\n";
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
}