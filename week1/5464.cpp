/*
알고리즘 : 구현
시간복잡도 : O(N)
    5*15 = 75
공간복잡도 : O(1)

접근 과정 :
    1) 대기 차량 : queue, 배열로 주차 공간 관리

풀이 시작 시간 : 2025.09.19 / 09:27
풀이 종료 시간 : 2025.09.19 / 09:54
*/

#include <iostream>
#include <queue>
using namespace std;

int parkingLot[101] = {0,};

int carWeight[2001];
int carParkingNum[2001];

int N,M;

int main(){
    int parkingIdx = 0;
    int income = 0;
    queue<int> waitQue;
    priority_queue<int, vector<int>, greater<int>> nextParkingNum;
    int carNum;
    scanf("%d %d", &N, &M);
    for(int i = 1; i<=N; i++){
        scanf("%d", &parkingLot[i]);
        nextParkingNum.push(i);
    }
    for(int i = 1; i<=M; i++){
        scanf("%d", &carWeight[i]);
    }

    
    for(int i = 0; i<2*M; i++){
        scanf("%d",&carNum);
        if(carNum > 0) waitQue.push(carNum);
        else nextParkingNum.push(carParkingNum[-carNum]);

        if(!nextParkingNum.empty() && !waitQue.empty()){
            int car = waitQue.front();
            waitQue.pop();

            int parkingNum = nextParkingNum.top();
            nextParkingNum.pop();
            income += parkingLot[parkingNum]*carWeight[car];
            carParkingNum[car] = parkingNum;

            // printf("parking %d %d\n",car,parkingNum);
        }
    }
    printf("%d",income);
}