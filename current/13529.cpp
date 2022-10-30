#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321;
typedef pair<int, int> point;

int dist[400010];
int N, K;

void solve()
{
    int res = INF;
    priority_queue<point, vector<point>, greater<point> > pq;
    pq.push(make_pair(0, N));
    dist[N] = 0;
    while (!pq.empty())
    {
        point top = pq.top();
        pq.pop();
        int cost = top.first;
        int cur = top.second;
        if (cur == K)
        {
            res = cost;
            break;
        }
        if (cur < 2 * K)
        {
            if(dist[cur - 1] > cost + 1){
                dist[cur - 1] = cost + 1;
                pq.push(make_pair(cost + 1, cur - 1));
            }
            if(dist[cur + 1] > cost + 1){
                dist[cur + 1] = cost + 1;
                pq.push(make_pair(cost + 1, cur + 1));
            }
            if(dist[cur * 2] > cost){
                dist[cur * 2] = cost;
                pq.push(make_pair(cost, cur * 2));
            }
        
        }
    }
    cout << res;
}
int main()
{
    cin >> N >> K;
    for(int i = 0 ; i <= 2* K;i++)
        dist[i] = INF;
    if(N >= K)
        cout << N - K;
    else
        solve();
}