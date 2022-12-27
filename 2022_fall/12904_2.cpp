#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    string t;
    
    cin >> s >> t;
    while(s.length() != t.length()){
        bool flag = false;
        if(t[t.length() - 1] == 'B')
            flag = true;
        t.erase(t.end()-1);
        if(flag)
            reverse(t.begin(),t.end());       
    }
    if(s == t)
        cout << 1;
    else
        cout << 0;
}