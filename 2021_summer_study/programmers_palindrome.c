#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int dp[2500] = {0};
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

int MAX(int  a, int b){
    return a > b ? a : b;
}
int solution(const char* s) {
    int answer = 0;
    int flag = 0;
    if(strlen(s)%2 == 0){
        for(int i=1;i<strlen(s);i++){
            for(int j=0; j<= strlen(s)/2 ;j++){
                if(i+j+1 < strlen(s) && i-j >= 0){
                    if(s[i+j+1] == s[i-j]){
                        dp[i] += 2;
                    }
                 else{ 
                     break;
                 }   
                }
            }
        }
        for(int i=0; i<strlen(s);i++)
            answer = MAX(answer,dp[i]);
    }
    if(1){
        for(int i=0;i<strlen(s);i++)
            dp[i] = 1;
        for(int i=1;i<strlen(s);i++){
            for(int j=1; j<= strlen(s)/2 ;j++){
                if(i+j < strlen(s) && i-j >= 0){
                    if(s[i+j] == s[i-j]){
                        dp[i] += 2;
                    }
                 else{ 
                     break;
                 }   
                }
            }
        }
    }
    for(int i=0; i<strlen(s);i++)
        answer = MAX(answer,dp[i]);
    return answer;
}
