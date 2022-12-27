#include <iostream>

using namespace std;

int main(){
    string s;
    string t;
    string ans;
    int tlen, slen, front, back;
    bool dir = false;
    
    cin >> s >> t;
    slen = s.length();
    back = t.length() - 1;
    front = 0;
    while(back - front  + 1 > slen){
        char cur;
        if(dir == false)
            cur = t[back--];
        else
            cur = t[front++];
        if(cur == 'B')
            dir = !dir;
    }
    ans = "";
    if(dir == false){
        for(int i = front; i <= back; i++)
            ans += t[i];
    }
    else{
        for(int i = back ; i >= front; i--)
            ans += t[i];
    }
    if(ans == s)
        cout << 1;
    else
        cout << 0;
}