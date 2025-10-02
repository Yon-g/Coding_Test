/*
알고리즘 : 구현
시간복잡도 : O(2^N)
공간복잡도 : O(N)

접근 과정 :
    1) 방향 8개로 나눠서 완탐, 방문한 곳의 값이 더 크면 업데이트
풀이 시간 : 20분
*/

#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int N,M;
int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,1,-1,-1};

int shark_map[51][51];
queue<pair<pair<int,int>,int>> que;
int main(){
    scanf("%d %d",&N,&M);

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            shark_map[i][j] = INF;
            int v;
            scanf("%d",&v);
            if(v == 1){
                shark_map[i][j] = 0;
                que.push({{i,j},0});
            }
        }
    }

    int result = 0;

    while(!que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int c = que.front().second;
        que.pop();
        for(int i = 0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = c + 1;
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(shark_map[nx][ny] <= nc) continue;
            shark_map[nx][ny] = nc;
            que.push({{nx,ny},nc});
            if(result < nc) result = nc;
        }
    }
    printf("%d",result);
}