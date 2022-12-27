#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001
typedef pair<int, int> point;

bool vis[100001];
int N, K;

void solve()
{
    priority_queue<point, vector<point>, greater<point> > pq;
    pq.push(make_pair(0, N));
    vis[N] = true;
    while (!pq.empty())
    {
        point top = pq.top();
        pq.pop();
        int cost = top.first;
        int cur = top.second;
        if (cur == K)
        {
            cout << cost;
            break;
        }
        if (cur < 2 * K)
        {
            if (cur * 2 < MAX && !vis[cur * 2])
            {
                vis[cur * 2] = true;
                pq.push(make_pair(cost, cur * 2));
            }
            if (cur - 1 >= 0 && !vis[cur - 1])
            {
                vis[cur - 1] = true;
                pq.push(make_pair(cost + 1, cur - 1));
            }
            if (cur + 1 < MAX && !vis[cur + 1])
            {
                vis[cur + 1] = true;
                pq.push(make_pair(cost + 1, cur + 1));
            }
        }
    }
}
int main()
{
    cin >> N >> K;
    if (N >= K)
         cout << N - K;
    else
        solve();
}