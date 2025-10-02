/*
알고리즘 : 구현
시간복잡도 : O(2^N)
공간복잡도 : O(N)

접근 과정 :
    1) 각 방향 그리는 함수, CCTV 마다 가진 방향으로 그리는 함수 호출
풀이 시간 : 1시간 21분
*/

#include <iostream>
#include <vector>
#define INF 987654321 

using namespace std;

int N,M;
int board[8][8];

vector<pair<int,int>> cctv;
int cctv_count = 0;
int result = INF;

void draw_direction(int direction, int x, int y){
    switch(direction){
        case 0 :{ // 상
            for(int i = 1;;i++){
                int nx = x-i;
                if(nx < 0) break;
                if(board[nx][y] == 6) break;
                else if(board[nx][y] > 0) continue;
                board[nx][y] = -1;
            }
            break;
        }
        case 1 :{ // 우
            for(int i = 1;;i++){
                int ny = y+i;
                if(ny >= M) break;
                if(board[x][ny] == 6) break;
                else if(board[x][ny] > 0) continue;
                board[x][ny] = -1;
            }
            break;
        }
        case 2 :{ // 하
            for(int i = 1;;i++){
                int nx = x+i;
                if(nx >= N) break;
                if(board[nx][y] == 6) break;
                else if(board[nx][y] > 0) continue;
                board[nx][y] = -1;
            }
            break;
        }
        case 3 :{ // 좌
            for(int i = 1;;i++){
                int ny = y-i;
                if(ny < 0) break;
                if(board[x][ny] == 6) break;
                else if(board[x][ny] > 0) continue;
                board[x][ny] = -1;
            }
            break;
        }
    }
}

int result_direct[8]; // 각 CCTV 방향 저장 배열

void draw_cctv(){ // 각 CCTV 그리기
    for(int i = 0; i<cctv_count; i++){
        int direction = result_direct[i];
        int c_x = cctv[i].first;
        int c_y = cctv[i].second;

        switch(board[c_x][c_y]){
            case 1 :{
                draw_direction(direction,c_x,c_y);
                break;
            }
            case 2 :{
                draw_direction(direction,c_x,c_y);
                draw_direction((direction+2)%4,c_x,c_y);
                break;
            }
            case 3 :{
                draw_direction(direction,c_x,c_y);
                draw_direction((direction+1)%4,c_x,c_y);
                break;
            }
            case 4 :{
                draw_direction(direction,c_x,c_y);
                draw_direction((direction+1)%4,c_x,c_y);
                draw_direction((direction+3)%4,c_x,c_y);
                break;
            }
            case 5 :{
                draw_direction(direction,c_x,c_y);
                draw_direction((direction+1)%4,c_x,c_y);
                draw_direction((direction+2)%4,c_x,c_y);
                draw_direction((direction+3)%4,c_x,c_y);
                break;
            }

        }
    }
    int zero_count = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            // printf("%2d ",board[i][j]);
            if(board[i][j] == 0) zero_count++;
            if(board[i][j] == -1) board[i][j] = 0;
        }
        // printf("\n");
    }
    // printf("\n");
    if(result > zero_count) result = zero_count;
}

void dfs(int n){
    if(n == cctv_count){
        // for(int i = 0; i<cctv_count; i++){
        //     printf("%d ",result_direct[i]);
        // }
        // printf("\n");
        draw_cctv();
        return;
    }
    for(int i = 0; i<4; i++){
        result_direct[n] = i;
        dfs(n+1);
    }
}

int main(){
    scanf("%d %d",&N,&M);
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            scanf("%d",&board[i][j]);
            if(board[i][j] != 0 && board[i][j] != 6){ //CCTV 일 경우
                cctv_count++; //CCTV 개수 증가
                cctv.push_back({i,j}); //CCTV 위치 저장
            }
        }
    }
    dfs(0);
    printf("%d",result);

}