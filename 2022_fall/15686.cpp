#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> point;
#define INF 987654321;
int mat[101][15];
int N, M,clen,hlen,a,ans = INF;
bool vis[15];
vector <point> chick;
vector <point> home;

void dfs(int cur, int cnt){
    if(cur == clen && cnt != M){
        return ;
    }
    if(cnt == M ){
        int res = 0;
        for(int i = 0 ; i < hlen ; i++){
            int loc_res = INF;
            for(int j = 0 ; j < clen ; j++){
                if(vis[j])
                    loc_res = min(loc_res,mat[i][j]);
            }
            res += loc_res;
        }
        if(res < ans)
            ans = res;
        return;
    }
    if(cnt < M){
        vis[cur] = true;
        dfs(cur + 1, cnt + 1);
        vis[cur] = false;
        dfs(cur + 1,cnt);
    }
}

int main (){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> a;
            if(a == 1) 
                home.push_back(make_pair(i,j));
            else if(a == 2)
                chick.push_back(make_pair(i,j));
        }
    }
    clen = chick.size();
    hlen = home.size();
    for(int i = 0 ; i < hlen ; i++){
        for(int j = 0 ; j < clen ; j++){
            mat[i][j] = abs(chick[j].first - home[i].first) + abs(chick[j].second - home[i].second);
        }
    }
    /*
    for(int i = 0 ; i < hlen ; i++){
        for(int j = 0 ; j < clen ; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }*/
    dfs(0,0);
    cout << ans;
}