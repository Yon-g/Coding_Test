/*
알고리즘 : 구현
시간복잡도 : O(N)
공간복잡도 : O(1)

접근 과정 :
    1) 주사위 하나의 층 값은 4,5,6 중에 하나
풀이 시간 : 31분
*/
#include <iostream>

using namespace std;

int N;
int reverse_face[6] = {5,3,4,1,2,0}; // 주사위 정반대의 인덱스 번호 매칭 (0,5),(1,3)...
int board[10000][6]; // 주사위 전체 저장 배열
int max_value(int up, int down){
    if(up == 6 || down == 6){ // 윗면과 아랫면 중 하나가 6이면
        if(up == 5 || down == 5){ // 윗면과 아랫면 중 하나가 5이면
            return 4; // 윗면 아랫면이 5와 6 이라 가장 큰 값 4
        }
        else{
            return 5; // 윗면 아랫면 제외 5가 제일 큰 값 
        }
    }
    else return 6; // 윗면 아랫면 제외 6이 제일 큰 값
}

int find_value_idx(int dice_num, int target){ //주사위에서 찾고있는 값의 인덱스 추출 함수
    for(int i = 0; i<6; i++){
        if(board[dice_num][i] == target) return i;
    }
}

int main(){
    scanf("%d",&N);

    for(int i = 0; i<N; i++){
        for(int j = 0; j<6; j++){
            scanf("%d",&board[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i<6; i++){
        int sum = 0;
        int up = board[0][i]; // 1번 주사위 윗면 번호
        int next_up_idx = reverse_face[find_value_idx(0,up)]; // 윗면 번호의 인덱스값
        int down = board[0][next_up_idx]; // 주사위 아랫면 번호
        sum += max_value(up,down);
        for(int j = 1; j<N; j++){ // 2번째 주사위부터 마지막까지 반복
            up = down; // 이전 주사위의 아랫면은 현재 주사위의 윗면
            next_up_idx = reverse_face[find_value_idx(j,up)]; // 윗면 번호의 인덱스값
            down = board[j][next_up_idx]; // 주사위 아랫면 번호  
            sum += max_value(up,down);
        }
        if(result < sum) result = sum;
    }
    printf("%d",result);
}