/*
알고리즘 : 구현
시간복잡도 : O(2^N)
공간복잡도 : O(N)

접근 과정 :
    1) 최대 값부터 왼쪽 없앤 경우, 오른쪽 없앤 경우 나눠서 재귀 후 결과 더하기
풀이 시간 : 21분
*/
#include <iostream>

using namespace std;

char arr[8];

int dfs(int top, int bot){
    if(top-bot == 1){
        if(arr[top] == arr[bot]) return 1;
        else return 2;
    }
    bool check_arr = true;
    for(int i = bot; i<top; i++){
        if(arr[i] != arr[i+1]) check_arr = false;
    }
    if(check_arr) return 1;
    return dfs(top-1,bot)+dfs(top,bot+1);
}

int main(){
    
    scanf("%s",&arr);
    int idx = 0;
    while(arr[idx] != '\0') idx++;
    int bot = 0;
    int top = idx-1;
    printf("%d",dfs(top,bot));
}