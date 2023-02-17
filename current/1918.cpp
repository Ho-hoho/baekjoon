#include <iostream>
#include <stack>

using namespace std;
string str;
stack <char> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str;
    for(int i = 0 ; i < str.size();i++){
        char cur = str[i];
        if(cur >= 'A' && cur <= 'Z')
            cout << cur;
        else{
            if(cur == '('){
                s.push(cur);
            }
            else if (cur == ')'){
                while(1){
                    if(s.top() == '('){
                        s.pop();
                        break;
                    }
                    cout << s.top();
                    s.pop();
                }
            }
            else if (cur == '*' || cur == '/'){
                while(!s.empty()){
                    if(s.top() == '*' || s.top() == '/'){
                        cout << s.top();
                        s.pop();
                    }
                    else break;
                }
                s.push(cur);
            }
            else if (cur == '+' || cur == '-'){
                while(!s.empty()){
                    if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'){
                        cout << s.top();
                        s.pop();
                    }
                    else break;
                }
                s.push(cur);
            }
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}