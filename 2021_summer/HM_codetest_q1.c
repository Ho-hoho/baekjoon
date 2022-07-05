#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// dice_rows는 2차원 배열 dice의 행 길이, dice_cols는 2차원 배열 dice의 열 길이입니다.
int arr[100001] ={0};
int mat[10][10] = {0};
int row,col;
int v[4] = {0};
int dfs(int i,int num,int times){
    if(v[i])
        return 0;
    v[i] = 1;
    for(int j=0;j<col;j++){
        arr[num+ mat[i][j]*times] = 1;
        for(int k=0;k<=row;k++){
            dfs(k,num+ mat[i][j]*times,times*10);
        }
    }
    v[i] = 0;
    return 0;
    
    
}

int solution(int** dice, size_t dice_rows, size_t dice_cols) {
    int answer = 0;
    int max_num = 1;
    row=dice_rows ; col = dice_cols;
    for(int i=0; i<dice_rows;i++){
        max_num*=10;
    }
    for(int i= 0; i<dice_rows;i++){
        for(int j=0; j<dice_cols;j++){
            arr[dice[i][j]] = 1;  
            mat[i][j] = dice[i][j];
        }
    }
    for(int i=0; i<dice_rows;i++){
        dfs(i,0,1);
    }
    answer=1;
    while(answer<= 10000){
        if(!arr[answer])
            break;
        answer++;
    }
    return answer;
}
