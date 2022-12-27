#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> point;

int N,x,y;
point arr[1000001];

int main (){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> x >> y;
        arr[i] = make_pair(x,y);
    }
    sort(arr, arr + N);
    
    int cur_s,cur_e,ans=0;
    cur_s = arr[0].first;
    cur_e = arr[0].second;
    for(int i = 1 ; i < N ; i++){
        if(cur_e >= arr[i].first ){
            if(cur_e < arr[i].second)
                cur_e = arr[i].second;
        }
        else{
            ans += cur_e - cur_s;
            cur_s = arr[i].first;
            cur_e = arr[i].second;
        }
    }
    ans += cur_e - cur_s;
    cout << ans;
}