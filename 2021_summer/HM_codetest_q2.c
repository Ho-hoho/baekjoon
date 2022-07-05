#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// a_len은 배열 a의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool* solution(const char* a[], size_t a_len) {
    bool* answer = (bool*)malloc(a_len*sizeof(bool));
    for(int idx = 0;idx<a_len;idx++){
        int s=0, e= strlen(a[idx])-1;        
        while(1){
            if(s == e && a[idx][s] == 'a'){
                answer[idx] = true;
                break;
            }
            if(s > e){
                answer[idx] = false;
                break;
            }
            if(a[idx][s] == 'b' && a[idx][e] == 'b'){
                s++; e--;
            }
            else if(a[idx][s] == 'a')
                s++;
            else if(a[idx][e] == 'a')
                e--;
            
        }
        
    }
    
    return answer;
    
}
