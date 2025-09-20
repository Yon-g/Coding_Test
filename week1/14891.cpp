/*
알고리즘 : 구현
시간복잡도 : O(N)
공간복잡도 : O(1)

접근 과정 :
    1) deque로 회전 구현, 재귀로 회전 탐색

풀이 시작 시간 : 2025.09.21 / 23:36
풀이 종료 시간 : 2025.09.21 / 00:06
*/

#include <iostream>
#include <deque>
using namespace std;

deque<int> wheelStatus[5];

enum Direction{
    CW = 1,
    CCW = -1,
    RIGHT = 2,
    LEFT = 6
};

int K;

void rotation(int wheelNum, int direction){ // 회전 시키기
    if(direction == CW){
        wheelStatus[wheelNum].push_front(wheelStatus[wheelNum].back());
        wheelStatus[wheelNum].pop_back();
    }
    else if(direction == CCW){
        wheelStatus[wheelNum].push_back(wheelStatus[wheelNum].front());
        wheelStatus[wheelNum].pop_front();
    }
}

int checkRotate(int wheelNum, int toward){ // 톱니 회전 시켜야되는지 확인
    if(toward == LEFT){
        return (wheelNum != 1 && wheelStatus[wheelNum][LEFT] != wheelStatus[wheelNum-1][RIGHT]);
    }
    else if(toward == RIGHT){
        return (wheelNum != 4 && wheelStatus[wheelNum][RIGHT] != wheelStatus[wheelNum+1][LEFT]);
    }
    return 0;
}

void rotateLeft(int wheelNum, int direction){ // 왼쪽 방향 회전 재귀
    if(wheelNum == 1){
        rotation(wheelNum,direction);
        return;
    }
    if(checkRotate(wheelNum,LEFT)){
        rotateLeft(wheelNum-1,-direction);
    }
    rotation(wheelNum,direction);
}

void rotateRight(int wheelNum, int direction){ // 오른쪽 방향 회전 재귀
    if(wheelNum == 4){
        rotation(wheelNum,direction);
        return;
    }
    if(checkRotate(wheelNum,RIGHT)){
        rotateRight(wheelNum+1,-direction);
    }
    rotation(wheelNum,direction);
}

int main(){
    for(int i = 1; i<5; i++){
        for(int j = 0; j<8; j++){
            int num;
            scanf("%1d",&num);
            wheelStatus[i].push_back(num);
        }
    }
    scanf("%d",&K);
    for(int i = 0; i<K; i++){
        int wheelNum, direction;
        scanf("%d %d",&wheelNum,&direction);

        if(checkRotate(wheelNum,LEFT)){
            rotateLeft(wheelNum-1,-direction);
        }

        if(checkRotate(wheelNum,RIGHT)){
            rotateRight(wheelNum+1,-direction);
        }
        rotation(wheelNum,direction);
    }
    int result = 0;
    int cal = 1;
    for(int i = 1; i<5; i++){
        if(wheelStatus[i][0]) result+=cal;
        cal*=2;
    }
    printf("%d",result);
}