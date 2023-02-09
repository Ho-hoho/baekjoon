#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int,int> point;

int tc, N,a,b;
vector <point > conv;
point start;
point dest;
bool vis[101];

int dist(point a, point b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void init(){
    conv.clear();
    memset(vis,false,sizeof(vis));
}

bool bfs(){
    queue <point> q;
    q.push(start);
    while(!q.empty()){
        point cur = q.front();
        q.pop();
        if(dist(cur,dest) <= 1000){
            return true;
        }
        for(int i = 0 ; i < conv.size() ;i++){
            if(!vis[i] && dist(cur,conv[i]) <= 1000){
                q.push(conv[i]);
                vis[i] = true;
            }
        }
    }
    return false;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> tc;
    while(tc--){
        init();
        cin >> N;
        cin >> a >> b;
        start = make_pair(a,b);
        for(int i = 0 ; i < N; i++){
            cin >> a >> b;
            conv.push_back(make_pair(a,b));
        }
        cin >> a >> b;
        dest = make_pair(a,b);
        if(bfs())
            cout << "happy\n";
        else
            cout << "sad\n";
        
    }
}