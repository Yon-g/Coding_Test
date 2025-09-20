/*
알고리즘 : 백트래킹, 소수판별
시간복잡도 : O(5^N)
    4*5*5*5*5*5*5*5 = 4*5^7 = 4*78125 = 312500 (dfs)
    312500 * 500 = 156,250,000(최악) : 1.5초
공간복잡도 : O(N)

접근 과정 :
    1) 에라토스테네스의 체로 접근 -> N이 커지면서 시간초과 가능
    2) 백트래킹 및 소수판별(2~루트n까지 탐색) -> 시간초과 x
        - 첫 자리 : 2,3,5,7
        - 그 외 자리 : 1,3,5,7,9
        - DFS로 탐색

풀이 시간 : 40분
*/

#include <iostream>
#include <cmath>
using namespace std;

int N;
int range;
int numArr[5] = {1,3,5,7,9};

int result[8];

int primary(int num){
    for(int i = 2; i<=sqrt(num); i++){
        if(num % i == 0) return 0;
    }
    return 1;
}

void dfs(int n, int num){
    if(n == N){
        printf("%d\n",num);
        return;
    }
    for(int i = 0; i<5; i++){
        int next = num*10 + numArr[i];
        if(primary(next)){
            dfs(n+1, next);
        }
    }
}

int main(){
    scanf("%d", &N);
    range = pow(10,N);
    dfs(1,2);
    dfs(1,3);
    dfs(1,5);
    dfs(1,7);
}
