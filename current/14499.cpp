#include <iostream>

using namespace std;

int N,M,x,y,k;
int mat[21][21];
int dice[7];
int dir[1001];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

void roll(int dir){
    int a;
    if(dir == 1){
        a = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = a;
    }
    else if(dir == 2){
        a = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = a;
    }
    else if(dir == 3){
        a = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = a;
    }
    else if(dir == 4){
        a = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = a;
    }
    
}

void pattern(){
    if(mat[x][y] == 0){
        mat[x][y] = dice[6];
    }
    else{
        dice[6] = mat[x][y];
        mat[x][y] = 0;
    }
}

void solve(){
    for(int ep = 0 ; ep < k ; ep++){
        if(x + dx[dir[ep]] >= 0 && x + dx[dir[ep]] < N
        && y + dy[dir[ep]] >= 0 && y + dy[dir[ep]] < M){
            x += dx[dir[ep]];
            y += dy[dir[ep]];
            roll(dir[ep]);
            pattern();
            cout << dice[1] << "\n";
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> x >> y >> k;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0; j < M;j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0 ; i < k ;i++)
        cin >> dir[i];
    solve();
    return 0;
}