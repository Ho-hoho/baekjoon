#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> point;

int N,M;
int org_mat[10][10];
int mat[10][10];
int way[6] = {-1,4,2,4,4,1};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans = 987654321;
vector <point> cctv;
vector <int> choice;

void fillLine(int x, int y, int dir){
    int k = 0;
    while(++k){
        int curx = x + dx[dir] * k;
        int cury = y + dy[dir] * k;
        if(curx >= 0 && curx < N && cury >=0 && cury < M && mat[curx][cury] != 6){
            if(mat[curx][cury] == 0){
                mat[curx][cury] = mat[x][y];
            }
        }
        else
            break;
    }
}

void fillMat(int x, int y,int wayIdx){
    int num = mat[x][y];

    if(num == 1){
            fillLine(x,y,wayIdx);
    }
    else if (num == 2){
        fillLine(x,y,wayIdx);
        fillLine(x,y,wayIdx + 2);
    }
    else if (num == 3){
        fillLine(x,y, wayIdx);
        if(wayIdx  == 3)
            fillLine(x,y, 0);
        else
            fillLine(x,y,wayIdx + 1);
    }
    else if (num == 4){
        for(int i = 0 ; i < 4 ;i++){
            if(wayIdx != i)
                fillLine(x,y,i);
        }
    }
    else if (num == 5){
        for(int i = 0 ; i < 4 ;i++)
            fillLine(x,y,i);
    }

}

void getArea(){
    int cnt = 0;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ;j++){
            mat[i][j] = org_mat[i][j];
        }
    }
    for(int i = 0 ; i < cctv.size();i++){
        fillMat(cctv[i].first,cctv[i].second,choice[i]);
    }
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M; j++){
            if(mat[i][j] == 0)
                cnt++;
        }
    }

    ans = min(ans,cnt);
}

void choose(int idx){
    if(idx == cctv.size()){
        getArea();
        return;
    }
    
    for(int k = 0 ; k < way[org_mat[cctv[idx].first][cctv[idx].second]]; k++){
        choice.push_back(k);
        choose(idx + 1);
        choice.pop_back();
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ; j++){
            cin >> org_mat[i][j];
            if(org_mat[i][j] >= 1 && org_mat[i][j] <= 5)
                cctv.push_back(make_pair(i,j));
        }
    }
    choose(0);
    cout << ans;
}