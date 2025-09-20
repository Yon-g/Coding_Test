/*
알고리즘 : 구현
시간복잡도 : O(N)
    5*15 = 75
공간복잡도 : O(1)

접근 과정 :
    1) 2차원 배열에 입력받고 열 단위로 출력

풀이 시작 시간 : 2025.09.19 / 09:16
풀이 종료 시간 : 2025.09.19 / 09:20
*/

#include <iostream>
#include <cstring>

using namespace std;

char arr[5][16];

int main(){
    memset(arr,0, sizeof(arr));
    for(int i = 0; i<5; i++){
        scanf("%s",arr[i]);
    }

    for(int i = 0; i<15; i++){
        for(int j = 0; j<5; j++){
            if(arr[j][i] == 0) continue;
            printf("%c",arr[j][i]);
        }
    }
}