#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> point;

int N, M, K;
int a, b, c, sum=0;
int A[11][11];
int soil[11][11];
int dx[8] = {1, 1, 0, -1, -1 , -1 ,0 ,1};
int dy[8] = {0, 1, 1, 1, 0 , -1, -1, -1};
vector<int> tree[11][11];
queue <pair<point,int> > q;


void spring(){
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ;j++){
            auto it = tree[i][j].begin();
            while(it != tree[i][j].end()){
                if(*it <= soil[i][j]){
                    soil[i][j] -= *it;
                    *it += 1;
                    it++;
                }
                else{
                    q.push(make_pair(make_pair(i,j),*it));
                    it = tree[i][j].erase(it);
                }
            }
        }
    }
    
}

void summer(){
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curage = q.front().second;
        q.pop();
        soil[curx][cury] += curage/2;
    }
}

void fall(){
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ;j++){
            auto it = tree[i][j].begin();
            while(it != tree[i][j].end()){
                if(((*it)%5) == 0){
                    for(int k = 0 ; k < 8 ;k++){
                        if(i + dx[k] >= 1 && i + dx[k] <= N && j + dy[k] >=1 && j + dy[k] <= N){
                            tree[i+dx[k]][j+dy[k]].insert(tree[i+dx[k]][j+dy[k]].begin(),1);
                        }
                    }
                }
                it++;
            }
        }
    }
}

void winter(){
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ;j++){
            soil[i][j] += A[i][j];
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ;j++){
            cin >> A[i][j];
            soil[i][j] = 5;
        }
    }
    for(int i = 0 ; i < M;i++){
        cin >> a >> b >> c;
        tree[a][b].push_back(c);
        sort(tree[a][b].begin(), tree[a][b].end());
    }
    
    while(K--){
        spring();
        summer();
        fall();
        winter();
    }
    
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1; j <= N; j++){
            sum += tree[i][j].size();
        }
    }
    cout << sum;
}