#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> point;
typedef struct _node{
    point rb;
    point bb;
    int t ;
    int flag = 0;
}Node;

string s;
enum {RIGHT,DOWN,LEFT,UP};
int N,M;
int mat[11][11];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
point srb,sbb;
queue <Node> q;

Node move(int dir, Node curNode){
    Node retNode;
    bool rev = false, fdone = false, sdone = false;
    point nfb,nsb;
    if(dir == RIGHT){
        if(curNode.rb.first == curNode.bb.first && curNode.rb.second < curNode.bb.second){
            nfb = curNode.bb;
            nsb = curNode.rb;
            rev = true;
        }
        else{
            nfb = curNode.rb;
            nsb = curNode.bb;
        }
    }
    else if (dir == DOWN){
        if(curNode.rb.second == curNode.bb.second && curNode.rb.first < curNode.bb.first){
            nfb = curNode.bb;
            nsb = curNode.rb;
            rev = true;
        }
        else{
            nfb = curNode.rb;
            nsb = curNode.bb;
        }
    }
    else if (dir == LEFT){
        if(curNode.rb.first == curNode.bb.first && curNode.rb.second > curNode.bb.second){
            nfb = curNode.bb;
            nsb = curNode.rb;
            rev = true;
        }
        else{
            nfb = curNode.rb;
            nsb = curNode.bb;
        }
    }
    else{
        if(curNode.rb.second == curNode.bb.second && curNode.rb.first > curNode.bb.first){
            nfb = curNode.bb;
            nsb = curNode.rb;
            rev = true;
        }
        else{
            nfb = curNode.rb;
            nsb = curNode.bb;
        }
    }

    while(1){
        nfb.first += dx[dir];
        nfb.second += dy[dir];
        if(mat[nfb.first][nfb.second] == 1){
            fdone = true;
            break;
        }
        if(mat[nfb.first][nfb.second] == -1){
            nfb.first -= dx[dir];
            nfb.second -= dy[dir];
            break;
        }
    }

    while(1){
        nsb.first += dx[dir];
        nsb.second += dy[dir];
        if(mat[nsb.first][nsb.second] == 1){
            sdone = true;
            break;
        }
        if(mat[nsb.first][nsb.second] == -1 || (nsb.first == nfb.first && nsb.second == nfb.second)){
            nsb.first -= dx[dir];
            nsb.second -= dy[dir];
            break;
        }
    }

    if(rev){
        if(fdone){
            retNode.flag = -1;
        }
        else if(sdone)
            retNode.flag = 1;
        else {
            retNode.flag = 0;   
        }
        retNode.rb = nsb;
        retNode.bb = nfb;
        retNode.t = curNode.t + 1;
    }
    else{
        if(sdone){
            retNode.flag = -1;
        }
        else if(fdone)
            retNode.flag = 1;
        else {
            retNode.rb = nfb;
            retNode.bb = nsb;
            retNode.t = curNode.t + 1;
            retNode.flag = 0;
            
        }
    }
    return retNode;
}

void solve(){
    Node newNode;
    newNode.rb = make_pair(srb.first,srb.second);
    newNode.bb = make_pair(sbb.first,sbb.second);
    newNode.t = 0;
    q.push(newNode);
    while(!q.empty()){
        Node curNode = q.front(); q.pop();
        Node mNode; 
        cout << "Red Ball : " << curNode.rb.first << " " << curNode.rb.second << "\n" << "Blue Ball : " << curNode.bb.first << " " << curNode.bb.second << " " << curNode.t << "\n";
        for(int k = 0 ; k < 4 ;k++){
            mNode = move(k,curNode);
            if(mNode.flag == 1) {
                cout << mNode.t; return;
            }        
            if(mNode.flag == -1){
                continue;
            }
            if(curNode.rb.first != mNode.rb.first || curNode.rb.second != mNode.rb.second 
            || curNode.bb.first != mNode.bb.first || curNode.bb.second != mNode.bb.second)
                if(mNode.t < 10)
                    q.push(mNode);
        }
        cout << "\n";    
    }
    cout << -1;
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N ; i++){
        cin >> s;
        for(int j = 0; j < M ;j++){
            if(s[j] == 'O')
                mat[i][j] = 1;
            else if (s[j] == '#')
                mat[i][j] = -1;
            else
                mat[i][j] = 0;
            if(s[j] == 'R')
                srb = make_pair(i,j);
            else if(s[j] == 'B')
                sbb = make_pair(i,j);
        }
    }
    solve();
    return 0;
}