#include <iostream>

using namespace std;

int node[10001];
int idx = 0,input;

void postOrder(int s , int e){
    int mid;

    if(s >= e)
        return;
    else if(s == e - 1){
        cout << node[s] << "\n";
        return;
    }
    for(mid = s + 1; mid < e ; mid++){
        if(node[mid] > node[s])
            break;
    }
    postOrder(s+1,mid);
    postOrder(mid,e);
    cout << node[s] << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(cin >> input){
        node[idx++] = input;
    }
    postOrder(0,idx);
}