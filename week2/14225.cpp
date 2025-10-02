/*
알고리즘 : 구현
시간복잡도 : O(2^N)
공간복잡도 : O(N)

접근 과정 :
    1) DFS로 만들 수 있는 값 전체 찾기 => 찾지 못한 가장 작은 값 찾기
풀이 시간 : 27분
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[20]; // 집합 저장 배열
bool num_visited[2000001]; // 20 * 100000이 부분 집합의 합 최대값
bool visited[20]; // 집합 방문 상태 저장 배열

void dfs(int n, int sum, int before){
    num_visited[sum] = true;
    if(n == N) return;
    for(int i = 0; i<N; i++){
        if(visited[i])continue;
        if(before >= i) continue;
        visited[i] = true;
        dfs(n+1,sum + num[i],i);
        visited[i] = false;
    }
}

int main(){
    scanf("%d",&N);

    for(int i = 0; i<N; i++){
        scanf("%d",&num[i]);
    }
    dfs(0,0,-1);
    int result = 0;
    while(num_visited[result]) result++;
    printf("%d",result);
}