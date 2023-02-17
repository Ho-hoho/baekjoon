#include <iostream>

using namespace std;
typedef pair<int,int> point;

point arr[27];
char a,b,c;
int N;

void preOrder(int idx){
    cout << (char)(idx + 'A');
    if(arr[idx].first != 0)
        preOrder(arr[idx].first);
    if(arr[idx].second != 0)
        preOrder(arr[idx].second);  
}

void inOrder(int idx){
    if(arr[idx].first != 0)
        inOrder(arr[idx].first);
    cout << (char)(idx + 'A');
    if(arr[idx].second != 0)
        inOrder(arr[idx].second);  
}

void postOrder(int idx){
    if(arr[idx].first != 0)
        postOrder(arr[idx].first);
    if(arr[idx].second != 0)
        postOrder(arr[idx].second);  
    cout << (char)(idx + 'A');
}

int main (){

    scanf("%d\n",&N);
    for(int i = 0 ; i < N ;i++){
        arr[i].first = 0;
        arr[i].second = 0;
    }
    for(int i = 0 ; i < N ;i++){
        scanf("%c %c %c\n",&a,&b,&c);
        if( b != '.')
            arr[a - 'A'].first = b - 'A';
        else
            arr[a - 'A'].first = 0;
        if( c != '.')
            arr[a - 'A'].second = c - 'A';
        else
            arr[a - 'A'].second = 0;        
    }
    
    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    
}