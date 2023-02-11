#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
class info{
    public:
        int x;
        int y;
        int z;
        int t;

    info(int _x, int _y,int _z, int _t){
        x = _x;
        y = _y;
        z = _z;
        t = _t;
    }
};

int L,R,C,ret;
char c;
int mat[40][40][40];
bool vis[40][40][40];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
info start(0,0,0,0);

int bfs(){
    queue<info> q;
    memset(vis,false,sizeof(vis));
    q.push(start);
    while(!q.empty()){
        int curx = q.front().x;
        int cury = q.front().y;
        int curz = q.front().z;
        int curt = q.front().t;
        q.pop();
        for(int d = 0 ; d < 6 ; d++){
            if(curx + dx[d] >= 0&& curx + dx[d] < R&&
            cury + dy[d] >= 0 && cury + dy[d] < C &&
            curz + dz[d] >= 0 && curz + dz[d] < L){
                if(mat[curx +dx[d]][cury +dy[d]][curz +dz[d]] == 2)
                    return curt + 1;
                if(!vis[curx +dx[d]][cury +dy[d]][curz +dz[d]] && mat[curx +dx[d]][cury +dy[d]][curz +dz[d]] == 0){
                    vis[curx +dx[d]][cury +dy[d]][curz +dz[d]] = true;
                    q.push(info(curx+dx[d],cury + dy[d],curz + dz[d],curt + 1));
                }
            }
        }
    }
    return 0;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    while(1){
        cin >> L >> R >> C;
        if(!L && !R && !C)
            break;
        for(int k = 0 ; k < L ;k++){
            for(int i = 0 ; i < R ; i++){
                for(int j = 0 ; j < C ;j++){
                    cin >> c;
                    if(c == 'S'){
                        mat[i][j][k] = 1;
                        start.x = i;
                        start.y = j;
                        start.z = k;
                        start.t = 0;
                    }
                    else if (c == 'E')
                        mat[i][j][k] = 2;
                    else if (c == '#')
                        mat[i][j][k] = -1;
                    else if (c == '.')
                        mat[i][j][k] = 0; 
                }
            }
        }
        ret = bfs();
        if(ret)
            cout << "Escaped in " << ret << " minute(s).\n";
        else
            cout << "Trapped!\n";

    }
}