#include <iostream>

using namespace std;

enum {UP,LEFT,DOWN,RIGHT};
int N,M,t = 0;
int curx,cury,curdir,nextx,nexty,nextdir;
int mat[55][55];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void input(){
    cin >> N >> M;
    cin >> curx >> cury >> curdir;
    if (curdir == 1) curdir = 3;
    else if (curdir == 3) curdir = 1;
    for(int i = 0 ; i < N;i++){
        for(int j = 0; j < M ;j++){
            cin >> mat[i][j]; 
        }
    }
}

void solve(){
    while(1){
        if(mat[curx][cury] == 0)
            t++;
        mat[curx][cury] = -1;
        int flag = false;
        for(int k = 1 ; k <= 4; k++){
            nextdir = (curdir + k) % 4;
            nextx = curx + dx[nextdir];
            nexty = cury + dy[nextdir];
            if(mat[nextx][nexty] == 0){
                flag = true;
                break;
            }
        }
        if(flag){
            curx = nextx;
            cury = nexty;
            curdir = nextdir;
        }
        else{
            nextdir = (curdir + 2) % 4;
            nextx = curx + dx[nextdir];
            nexty = cury + dy[nextdir];
            if(mat[nextx][nexty] == -1){
                curx = nextx;
                cury = nexty;
            }
            else if (mat[nextx][nexty] == 1){
                cout << t;
                return;
            }
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    return 0;
}