#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R,C;
int arr[55][55];
typedef pair<int,int> point;
queue <point> wq;
queue <point> sq;
char c;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void fillWater(){
    int t = wq.size();
    while(t--){
        point cur = wq.front(); 
        wq.pop();
        for(int k = 0 ; k < 4 ; k++){
            if(arr[cur.first + dx[k]][cur.second + dy[k]] == 0 || arr[cur.first + dx[k]][cur.second + dy[k]] == 2){
                arr[cur.first + dx[k]][cur.second + dy[k]] = 1;
                wq.push(make_pair(cur.first + dx[k],cur.second + dy[k]));
            }
        }
    }
}

bool moveS(){
    int t = sq.size();
    while(t--){
        point cur = sq.front(); 
        sq.pop();
        for(int k = 0 ; k < 4 ; k++){
            if(arr[cur.first + dx[k]][cur.second + dy[k]] == 0 ){
                arr[cur.first + dx[k]][cur.second + dy[k]] = 2;
                sq.push(make_pair(cur.first + dx[k],cur.second + dy[k]));
            }
            else if(arr[cur.first + dx[k]][cur.second + dy[k]] == 3)
                return true;
        }
    }
    return false;
}

void Solve(){
    int t = 1;
    bool flag = false;
    while(1){
        fillWater();
        if(!sq.size())
            break;
        else if(moveS()){
            flag = true;
            break;
        }
        t++;
    }
    if(flag)
        cout << t;
    else
        cout << "KAKTUS";
}

void Input(){
    cin >> R >> C;
    memset(arr,-1,sizeof(arr));
    for(int i = 1 ; i <= R ; i++){
        for(int j = 1 ; j <= C ;j++){
            cin >> c;
            if(c == '.'){
                arr[i][j] = 0 ;
            }
            else if(c == '*'){
                arr[i][j] = 1;
                wq.push(make_pair(i,j));
            }
            else if(c == 'S'){
                arr[i][j] = 2;
                sq.push(make_pair(i,j));
            }
            else if(c == 'D'){
                arr[i][j] = 3;
            }
            else if(c == 'X'){
                arr[i][j] = -1;
            }
        }
    }
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Input();
    Solve();

}