#include <iostream>

using namespace std;

int n,m,op,a,b;
int parent[1000001];

int Find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int xp = Find(x);
    int yp = Find(y);
    if(xp != yp){
        if(xp <= yp)
            parent[yp] = xp;
        else
            parent[xp] = yp;
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i <= n ; i++)
        parent[i] = i;
    for(int i = 0 ; i < m; i++){
        cin >> op >> a >> b;
        if(op == 0){
            Union(a,b);
        }
        else if(op == 1){
            if(Find(a) != Find(b))
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}