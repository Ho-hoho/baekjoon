#include <iostream>
#include <algorithm>
using namespace std;

int N,M ;
long long s,e,mid,maxval=0;
long long arr[100001];
long long sum,ans;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0 ; i < N ;i++){
        cin >> arr[i];
        maxval = max(maxval,arr[i]);
    }
    s = 0; e = maxval * M;
    while(s <= e){
        mid = (s + e) / 2;
        
        sum = 0;
        for(int i = 0 ; i < N ; i++){
            sum += mid/arr[i];
        }
        
        if(sum >= M){
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    cout << ans;
}