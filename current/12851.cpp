#include <iostream>
#include <queue>

#define INF 987654321
#define INFP 100001
using namespace std;
typedef pair<int,int> point;

int s,e,ans,cnt=0,flag = INF;
bool vis[100001];
queue <point> q;
queue <point> tq;
int curt,curp;
void check(int nextp){
    tq.push(make_pair(curt+1 , nextp));
    if(nextp == e){
        flag = curt ;
        ans = curt + 1;
        cnt++;
    }
}

void bfs(){
    tq.push(make_pair(0,s));
    while(flag == INF && !tq.empty()){
        while(!tq.empty()){
            q.push(tq.front());
            vis[tq.front().first] = true;
            tq.pop();
            
        }
        while(!q.empty()){
            curt = q.front().first; 
            curp = q.front().second;
            q.pop();
            if(curt > flag)
                break;
            if(curp - 1 >= 0 && !vis[curp - 1]){
                check(curp - 1);
            }
            if(curp + 1 < INFP && !vis[curp + 1]){
                check(curp + 1);
            }
            if(curp * 2 < INFP && !vis[curp * 2]){
                check(curp * 2);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> e;
    
    bfs();
    cout << ans << "\n" << cnt;
    
}