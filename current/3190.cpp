#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

typedef pair<int,char> pic;
int mat[110][110] = {0};

priority_queue < pic, vector<pic> , greater<pic> >  dinfo;
deque<pair<int,int> > dq;
int dir;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N, K, L;
int a, b, ret = 0;
char c;

void changeDir(char d){
    if(d == 'D')
        dir = (dir + 1) % 4;
    else if(d == 'L'){
        dir -= 1;
        if(dir == -1)
            dir += 4;
    }
}

bool valid(int x, int y){
    if( mat[x][y] == 1 || mat[x][y] == -1)
        return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0 ; i <= N + 1;i++){
        mat[i][0] = -1;
        mat[0][i] = -1;
        mat[i][N + 1] = -1;
        mat[N + 1][i] = -1;
    }
    cin >> K;
    for(int i = 0 ; i < K ;i++){
        cin >> a >> b;
        mat[a][b] = 2;
    }
    cin >> L;
    for(int i = 0 ; i < L ;i++){
        cin >> a >> c;
        dinfo.push(make_pair(a,c));
    }
    
    dir = 0;
    dq.push_front(make_pair(1,1));
    while(1){
        ret++;
        int curx = dq.front().first + dx[dir];
        int cury = dq.front().second + dy[dir];
        if(valid(curx,cury)){
            dq.push_front(make_pair(curx,cury));
            if(mat[curx][cury] != 2){
                mat[dq.back().first][dq.back().second] = 0;
                dq.pop_back();
            }
            mat[curx][cury] = 1;
            if(!dinfo.empty() && ret == dinfo.top().first){
                changeDir(dinfo.top().second);
                dinfo.pop();
            }
        }
        else{
            break;
        }
    }
    cout << ret;
}