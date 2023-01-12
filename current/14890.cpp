#include <iostream>
#include <algorithm>
using namespace std;
int N, L,a;
int mat[101][101] = {0};
int arr[101];
int ans = 0,idx,cnt;

bool validUp(){
    if(cnt >= L)
        return true;
    return false;
}

bool validDown(){
    for(int i = 1 ; i <= L ;i++){
        if(arr[idx] - 1 != arr[idx + i])
            return false;
    }
    return true;
}

bool checkRoad(){
    idx = 0;
    cnt = 1;
    while(1){
        if(idx == N - 1)
            return true;
        if(arr[idx] == arr[idx + 1]){
            idx++;
            cnt++;
        }
        else if (arr[idx] + 1== arr[idx + 1]){
            if(validUp()){
                idx++;
                cnt = 1;
            }
            else
                return false;
        }
        else if (arr[idx] - 1 == arr[idx + 1]){
            if(validDown()){
                idx++;
                cnt = 1 - L;
            }
            else return false;
        }
        else
            return false;
    }

}
int main (){
    cin >> N >> L;
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < N ;j++){
            cin >> a;
            mat[i][j] = a;
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ;j++){
            arr[j] = mat[i][j];
        }
        if(checkRoad()) ans++;
        for(int j = 0 ; j < N ;j++){
            arr[j] = mat[j][i];
        }
        if(checkRoad()) ans++;
    }
    cout << ans;
}