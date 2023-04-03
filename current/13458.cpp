#include <iostream>

using namespace std;
long long arr[1000001];
long long b,c;
long long N;
long long cnt;

int main (){
    cin >> N;
    for(int i = 0 ; i < N ;i++)
        cin >> arr[i];
    cin >> b >> c;
    cnt = N;
    for(int i = 0 ; i < N ;i++){
        arr[i] -= b;
        if(arr[i] > 0){
            if(arr[i] % c) cnt++;
            cnt += (arr[i] / c);
        }
    }
    cout << cnt;
}