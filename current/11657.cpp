#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;
int N,M,a,b,c;
vector<pair<pair<int, int>, int> > edge;
long long dist[510];
long long from,to,cost;

bool bellmanFord(){
    for(int k = 1 ; k <= N - 1;k++){
        for(int i = 0 ; i < edge.size() ; i++){
            from = edge[i].first.first;
            to = edge[i].first.second;
            cost = edge[i].second;
            if(dist[from] != INF){
                if(dist[to] > dist[from] + cost)
                    dist[to] = dist[from] + cost;
            }
        }
    }

    for(int i = 0 ; i < edge.size() ;i++){
        from = edge[i].first.first;
        to = edge[i].first.second;
        cost = edge[i].second;
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

    cin >> N >> M;
    for(int i = 0 ; i < M ;i++){
        cin >> a >> b >> c;
        edge.push_back(make_pair(make_pair(a,b),c));
    }
    dist[1] = 0;
    for(int i = 2 ; i <= N ; i++){
        dist[i] = INF;
    }

    if(!bellmanFord()){
        cout << -1;
    }
    else{
        for(int i = 2 ; i <= N ; i++){
            if(dist[i] != INF){
                cout << dist[i] << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }

}