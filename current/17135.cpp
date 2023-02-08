#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX(a,b) a > b ? a : b;
using namespace std;
typedef pair<int,int> point;


int N, M, D, ans = 0;
int dx[3] = {0,-1,0};
int dy[3] = {-1,0,1};
int orgmat[20][20];
int mat[20][20];
vector <int> arch;

void simul(){
    int loc = N+1;
    int ret = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ;j++){
            mat[i][j] = orgmat[i][j];
        }
    }
    while(loc--){
        queue<point> victim;
        for(auto i : arch){
            bool flag = false;
            queue<pair<point,int> > q;
            bool vis[20][20];
            memset(vis,false,sizeof(vis));
            q.push(make_pair(make_pair(loc,i),0));
            while(!q.empty()){
                int curx = q.front().first.first;
                int cury = q.front().first.second;
                int curdis = q.front().second;
                q.pop();
                if(curdis + 1 > D)
                    continue;
                for(int k = 0 ; k < 3 ; k++){
                    if(curx + dx[k] >=0 && curx + dx[k] < loc && cury + dy[k] >= 0 && cury + dy[k] < M && !vis[curx + dx[k]][cury + dy[k]]){
                        if(mat[curx + dx[k]][cury + dy[k]] == 1){
                            victim.push(make_pair(curx + dx[k],cury + dy[k]));
                            flag = true;
                            break;
                        } 
                        else if (mat[curx + dx[k]][cury + dy[k]] == 0){
                            q.push(make_pair(make_pair(curx + dx[k],cury + dy[k]),curdis + 1));
                            vis[curx + dx[k]][cury + dy[k]] = true;
                        }
                    }
                }
                if(flag) break;
            }
        }
        while(!victim.empty()){
            int curx = victim.front().first;
            int cury = victim.front().second;
            victim.pop();
            if(mat[curx][cury] == 1){
                mat[curx][cury] = 0;
                ret++;
            }
        }
    }
    ans = MAX(ans,ret);
}

void choose(int idx){
    if(arch.size() == 3){
        simul();
        return;
    }
    else if (idx == M){
        return;
    }
    arch.push_back(idx);
    choose(idx + 1);
    arch.pop_back();
    choose(idx + 1);
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> D;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ;j++){
            cin >> orgmat[i][j];
        }
    }

   choose(0);  
   cout << ans;

}