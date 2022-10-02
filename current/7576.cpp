#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int mat [1010][1010];
int n,m,tom = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
class Info{
    public :
        int x;
        int y;
        int d;
        void setInfo(int _x,int _y,int _d){
            x = _x;
            y = _y;
            d = _d;
        }
};
queue <Info> q;

int tick(){
    int ret = 0;
    int day = 0;
    Info cur,temp;
    while(!q.empty()){
        cur = q.front();
        if(cur.d == day){
            q.pop();
            for (int k = 0; k < 4; k++){
                if (mat[cur.x][cur.y] > 0 && !mat[cur.x + dx[k]][cur.y + dy[k]]){
                    mat[cur.x + dx[k]][cur.y + dy[k]] = mat[cur.x][cur.y] + 1;
                    temp.setInfo(cur.x + dx[k], cur.y + dy[k], mat[cur.x][cur.y] + 1);
                    q.push(temp);
                    ret++;
                }
            }
        }
        else
            day++;
    }
    if(ret == tom)
        return day;
    else
        return 0;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Info temp;
    cin >> n >> m;
    for(int i = 0 ; i <= m + 1; i++){
        for(int j = 0 ; j <= n + 1; j++){
            if(i == 0 || i == m + 1 || j == 0 || j == n + 1)
                mat[i][j] = -1;
            else{            
                cin >> mat[i][j];
                if(mat[i][j] == 1){
                    temp.setInfo(i,j,0);
                    q.push(temp);
                }
                else if(mat[i][j] == 0)
                    tom++;
            }
        }    
    }
    if(tom == 0)
        cout << 0;
    else
        cout << tick() - 1;
}