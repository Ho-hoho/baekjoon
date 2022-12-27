#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> point;
int N;
vector <point> arr;
priority_queue <int,vector<int>,greater<int> > q;
int a,b;
int ans = 1;

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end());
    q.push(arr[0].second);
    for(int i = 1; i < N ; i++){
        int top = q.top();
        int curs = arr[i].first;
        int curt = arr[i].second;
        if(curs < top){
            ans++;
            q.push(curt);
        }
        else{
            q.pop();
            q.push(curt);
        }
    }
    cout << ans;
}