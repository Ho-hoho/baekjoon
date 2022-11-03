#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> point;

#define INF 987654321

int M, N;
int mat[101][101];
int dist[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dij(){
    int pos=0;
    priority_queue <point, vector<point>,greater<point> > pq;
    pq.push(make_pair(0,0));
    dist[0][0] = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int curx = pq.top().second / M;
        int cury = pq.top().second % M;
        pq.pop();
        if(cost > dist[curx][cury]) continue;
        for(int k = 0 ; k < 4 ; k++){
            int nextx = curx + dx[k];
            int nexty = cury + dy[k];
            if(nextx >= 0 && nextx < N && nexty >= 0 && nexty < M){
                int next_cost = cost + mat[nextx][nexty];
                if( next_cost < dist[nextx][nexty]){
                    dist[nextx][nexty] = next_cost;
                    pq.push(make_pair(next_cost, nextx * M + nexty));
                }
            }
        }
    }
    return dist[N-1][M-1];
}

int main (){
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%1d",&mat[i][j]);
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            dist[i][j] = INF;
        }
    }
    cout << dij();
}