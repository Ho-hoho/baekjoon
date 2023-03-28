#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
enum {RIGHT,DOWN,LEFT,UP};
int N,ans = 0;
int org_mat[21][21];
int mat[21][21];
int arr[21];
int choice[5];

void update_max(){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            if(mat[i][j] > ans)
                ans = mat[i][j];
        }
    }
}

void set_arr(int dir, int k){
    int idx = 0;
    memset(arr,0,sizeof(arr));
    if(dir == RIGHT){
        for(int i = N - 1 ; i >= 0; i--){
            if(mat[k][i]){
                arr[idx++] = mat[k][i];
            }
        }
    }
    else if (dir == DOWN){
        for(int i = N - 1 ; i >= 0 ;i--){
            if(mat[i][k])
                arr[idx++] = mat[i][k];
        }
    }
    else if (dir == LEFT){
        for(int i = 0 ; i < N ;i++){
            if(mat[k][i])
                arr[idx++] = mat[k][i];
        }
    }
    else if (dir == UP){
        for(int i = 0 ; i < N ;i++){
            if(mat[i][k])
                arr[idx++] = mat[i][k];
        }
    }
}

void set_line(int dir, int k){
    int temp[21] = {0};
    int idx = 0;
    for(int i = 0 ; i < N ;i++){
        if(arr[i]) temp[idx++] = arr[i];
    }
    if(dir == RIGHT ){
        for(int i = N - 1 ; i >= 0; i--){
            mat[k][i] = temp[i];
        }
    }
    else if (dir == DOWN){
        for(int i = N - 1 ; i >= 0 ;i--){
            mat[i][k] = temp[i];
        }
    }
    else if (dir == LEFT){
        for(int i = 0 ; i < N ;i++){
            mat[k][i] = temp[i];
        }
    }
    else if (dir == UP){
        for(int i = 0 ; i < N ;i++){
            mat[i][k] = temp[i];
        }
    }
}

void move(int dir){
    for(int i = 0 ; i < N ;i++){
        set_arr(dir,i);
        for(int i = 0 ; i < N ;i++){
            if(arr[i] == arr[i+1]){
                arr[i] += arr[i+1];
                arr[i+1] = 0;
            }
        }
        set_line(dir, i);
    }
}

void simul(){
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++)
            mat[i][j] = org_mat[i][j];
    }
    
    for(int i = 0 ; i < 5; i++){
        move(choice[i]);
    }
    update_max();
}

void choose(int cnt){
    if(cnt == 5){
        simul();
        return ;
    }
    for(int k = 0 ; k < 4 ; k++){
        choice[cnt] = k;
        choose(cnt + 1);
    }
    return;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            cin >> org_mat[i][j];
        }
    }
    choose(0);
    cout << ans;
}