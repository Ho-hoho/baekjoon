#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int > point;

int A, B ,C, a, b, c;
bool vis[210][210];
vector <int> ans;
queue <point> q;
point pour(int from, int to, int toMax){
    if(from == 0 || to == toMax)
        return make_pair(-1,-1);
    if(from + to >= toMax){
        return make_pair(from - (toMax - to),toMax);
    }
    else{
        return make_pair(0, from + to);
    }
}

void bfs(){
    q.push(make_pair(0,0));
    vis[0][0] = true;
    while(!q.empty()){
        a = q.front().first;
        b = q.front().second;
        c = C - a - b;
        q.pop();
        if(a == 0){
            ans.push_back(c);
        }
        
            point cur;
            cur = pour(a,b,B);
            if(cur.first != -1 && !vis[cur.first][cur.second]){
                q.push(make_pair(cur.first,cur.second));
                vis[cur.first][cur.second] = true;
            }
            cur = pour(a,c,C);
            if(cur.first != -1 && !vis[cur.first][C - (cur.first + cur.second)]){
                q.push(make_pair(cur.first,C - (cur.first + cur.second)));
                vis[cur.first][C - (cur.first + cur.second)] = true;
            }
            cur = pour(b,a,A);
            if(cur.first != -1 && !vis[cur.second][cur.first]){
                q.push(make_pair(cur.second,cur.first));
                vis[cur.second][cur.first] = true;
            }
            cur = pour(b,c,C);
            if(cur.first != -1 && !vis[C - (cur.first + cur.second)][cur.first]){
                q.push(make_pair(C - (cur.first + cur.second),cur.first));
                vis[C - (cur.first + cur.second)][cur.first] = true;
            }
            cur = pour(c,a,A);
            if(cur.first != -1 && !vis[cur.second][C - (cur.first + cur.second)]){
                q.push(make_pair(cur.second,C - (cur.first + cur.second)));
                vis[cur.second][C - (cur.first + cur.second)] = true;
            }
            cur = pour(c,b,B);
            if(cur.first != -1 && !vis[C - (cur.first + cur.second)][cur.second]){
                q.push(make_pair(C - (cur.first + cur.second),cur.second));
                vis[C - (cur.first + cur.second)][cur.second] = true;
            }
        
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;

    bfs();
    sort(ans.begin(),ans.end());
    for(auto i : ans)
        cout << i << " ";
}