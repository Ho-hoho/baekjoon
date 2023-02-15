#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<ll,ll> point;
int tc;
int N, M, W, S, E, T;
ll dist[501];
vector <pair<ll ,point> > edges;

void init(){
    for(int i = 1 ; i <= N; i++){
        dist[i] = INF;
    }
    edges.clear();
}

bool bellmanford(){
    for(int i = 1 ; i <= N; i++){
        for(auto e : edges){
            ll from = e.second.first;
            ll to = e.second.second;
            ll cost = e.first;
            if(dist[from] != INF){
                if(dist[to] > dist[from] + cost)
                    dist[to] = dist[from] + cost;
            }
        }
    }
    for(auto e : edges){
        ll from = e.second.first;
        ll to = e.second.second;
        ll cost = e.first;
        if(dist[from] != INF){
            if(dist[to] > dist[from] + cost)
                return false;
        }
    }
    return true;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> N >> M >> W;
        init();
        for(int i = 0 ; i < M ;i++){
            cin >> S >> E >> T;
            edges.push_back(make_pair(T,make_pair(S,E)));
            edges.push_back(make_pair(T,make_pair(E,S)));
            dist[E] = T;
            dist[S] = T;
        }
        
        for(int i = 0 ; i < W; i++){
            cin >> S >> E >> T;
            edges.push_back(make_pair(-T,make_pair(S,E)));
            dist[E] = -T;
        }
        if(!bellmanford()){  
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}