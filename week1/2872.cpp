/*
알고리즘 : 구현
시간복잡도 : O(N)
공간복잡도 : O(1)

접근 과정 :
    1) 책마다 부모, 자식 노드 할당해서 링크드 리스트로 책 쌓기 구현 -> 불필요한 구현
    2) 배열 마지막부터 처음까지 가장 큰숫자부터 차례대로 찾기

풀이 시작 시간 : 2025.09.19 / 10:10
풀이 종료 시간 : 2025.09.19 / 10:48
*/
#include <iostream>
#define PARENT 0
#define CHILD 1
using namespace std;

int N;

int bookList[300000];

int main(){
    scanf("%d",&N);

    for(int i = 0; i<N; i++){
        scanf("%d",&bookList[i]);
    }

    int findNum = N;
    for(int i = N-1; i>=0; i--){
        if(bookList[i] == N) N--;
    }

    printf("%d",N);

}