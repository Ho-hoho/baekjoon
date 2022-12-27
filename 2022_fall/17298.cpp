#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int N;
int arr[1000001];
int dp[1000001];
typedef pair<int, int> point;
stack <point> s;
int main (){
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < N ; i++){
        if(!s.empty()){
            if(s.top().first < arr[i]){
                while(!s.empty() && s.top().first < arr[i]){
                    dp[s.top().second] = arr[i];
                    s.pop();
                }
            }
            s.push(make_pair(arr[i],i));
        }
        else
            s.push(make_pair(arr[i],i));
    }
    for(int i = 0 ; i < N;i++)
        cout << dp[i] << " ";
    return 0;
}