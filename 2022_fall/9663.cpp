#include <iostream>

using namespace std;

int n, ans = 0;
int arr[16];

bool promising(int d){
    int i = -1;

    while(++i < d){
        if(arr[i] == arr[d] || abs(arr[i] - arr[d]) == d - i)
            return false;
    }
    return true;
}

void nqueens(int d){
    int i;
    if(d == n){
        ans++;
        return ;
    }
    for(int i = 0; i < n ; i++){
        arr[d] = i;
        if(promising(d))
            nqueens(d + 1);
    }
}

int main(){
    cin >> n;
    nqueens(0);
    cout << ans;
}