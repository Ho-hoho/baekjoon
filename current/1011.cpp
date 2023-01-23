#include <iostream>
#include <vector>

using namespace std;

int tc,x,y;
int sum = 0, num= 1,cnt = 0,val = 0;
vector<pair<int,int>> dp;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> tc;

    while(sum >= 0){
        sum += num;
        val++;
        dp.push_back(make_pair(sum,val));
        cnt = 1- cnt;
        if(cnt == 0){
            num += 1;
        }
    }
    dp.push_back(make_pair(2147483647,val));
    while(tc--){
        cin >> x >> y;
        y = y - x;
        for(auto i : dp){
            if(y <= i.first){
                cout << i.second << "\n";
                break;
            }
        }
    }
    
}