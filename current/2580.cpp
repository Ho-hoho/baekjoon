#include <iostream>
#include <cstring>
using namespace std;

int mat[10][10];
bool flag = false;

bool promising(int x, int y){
    int check[10];
    memset(check,0,sizeof(check));
    for(int i = 0 ; i < 9 ; i++){
        if(mat[x][i] && check[mat[x][i]])
            return false;
        check[mat[x][i]]++;
    }
    memset(check,0,sizeof(check));
    for(int i = 0 ; i < 9 ; i++){
        if(mat[i][y] && check[mat[i][y]])
            return false;
        check[mat[i][y]]++;
    }
    x -= x % 3;
    y -= y % 3;
    memset(check,0,sizeof(check));
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            if(mat[i][j] && check[mat[i][j]])
                return false;
            check[mat[i][j]]++;
        }
    }
    return true;
}

void    solve(int pos){
    if(!flag){
        int x = pos / 9;
        int y = pos % 9;
        if(x == 9 && y == 0){
            for(int i = 0; i < 9 ; i++){
                for(int j = 0 ; j < 9 ; j++)
                    cout << mat[i][j] << " ";
                cout << "\n";
            }
            flag = 1;
            return;
        }
        if(mat[x][y])
            solve(pos + 1);
        else{
            int val = 1;
            while(val < 10){
                mat[x][y] = val;
                if(promising(x,y)){
                    solve(pos + 1);
                }
                mat[x][y] = 0;
                val++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin >> mat[i][j];
    solve(0);
}