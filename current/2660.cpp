#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100
using namespace std;
int arr[51][51];
int N,a,b;

int main(){
    cin >> N;
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ; j++){
            arr[i][j] = INF;
        }
        arr[i][i] = 0;
    }
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1)
            break;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <= N ; i ++){
            for(int j = 1 ; j <= N ; j++){
                arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }
    vector <int> ans ;
    int ans_dist = INF;
    for(int i = 1 ; i <= N ; i++){
        int row = 0;
        for(int j = 1 ; j <= N;j++){
            row = max(row,arr[i][j]);
        }
        if(row < ans_dist){
            ans_dist = row;
            ans.clear();
            ans.push_back(i);
        }
        else if(row == ans_dist)
            ans.push_back(i);
    }

    cout << ans_dist << " " << ans.size() << "\n";
    for(int i = 0 ; i < ans.size(); i++)
        cout << ans[i] << " ";
}