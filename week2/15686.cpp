/*
알고리즘 : 구현
시간복잡도 : O(2^N)
공간복잡도 : O(N)

접근 과정 :
    1) 각 방향 그리는 함수, CCTV 마다 가진 방향으로 그리는 함수 호출
풀이 시간 : 27분
*/

#include <iostream>
#include <vector>
#include <cmath>
#define INF 987654321

using namespace std;

int N,M;
bool chicken_visited[13];

int result = INF;

vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
vector<pair<int,int>> chose_chicken;

void dfs(int n, int before){
    if(n == M){
        int chicken_dist = 0;
        for(int i = 0; i<house.size(); i++){
            int h_x = house[i].first;
            int h_y = house[i].second;

            int dist = INF;
            for(int j = 0; j<M; j++){
                int c_x = chose_chicken[j].first;
                int c_y = chose_chicken[j].second;
                int cost = abs(h_x-c_x) + abs(h_y-c_y);
                if(dist > cost) dist = cost;
            }
            chicken_dist+= dist;
        }
        if(chicken_dist < result) result = chicken_dist;
        return;
    }
    for(int i = 0; i<chicken.size(); i++){
        if(chicken_visited[i]) continue;
        if(i <= before) continue;
        chicken_visited[i] = true;
        chose_chicken.push_back(chicken[i]);
        dfs(n+1,i);
        chose_chicken.pop_back();
        chicken_visited[i] = false;
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int v;
            scanf("%d",&v);
            if(v == 1) house.push_back({i,j});
            if(v == 2) chicken.push_back({i,j});
        }
    }
    dfs(0,-1);
    printf("%d",result);
}