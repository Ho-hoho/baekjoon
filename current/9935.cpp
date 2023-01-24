#include <iostream>
#include <stack>

using namespace std;

string str;
string bset;
int slen,blen,lev=0;
stack <pair<char,int>> s;
string ans = "";
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str >> bset;
    slen = str.length();
    blen = bset.length();

    for(int i = 0 ; i < slen; i++){
        if(str[i] == bset[lev])
            lev++;
        else if (str[i] == bset[0])
            lev = 1;
        else
            lev = 0;
        s.push(make_pair(str[i],lev));
        if(lev == blen){
            for(int k = 0 ; k < blen ; k++)
                s.pop();
            if(!s.empty())
                lev = s.top().second;
            else
                lev = 0;
        }
    }

    if(!s.size())
        cout << "FRULA";
    else{
        while(!s.empty()){
            ans += s.top().first;
            s.pop();
        }
        for(int i = ans.length(); i >=0 ; i--)
            cout << ans[i];
    }
    
}