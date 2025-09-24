/*
알고리즘 : 구현
시간복잡도 : O(N)
공간복잡도 : O(1)

접근 과정 :
    1) y=x, y=-x 기준으로 주어진 x',y'을 통해 value 추출
풀이 시간 : 40분
*/

#include <iostream>
#include <cmath>
using namespace std;

// (2n+1)^2
// (2n+1)^2 - 2n
// (2n+1)^2 - 4n
// (2n+1)^2 - 6n

int returnValue(int x, int y){
    int n;
    if(abs(x) > abs(y)) n = abs(x);
    else n = abs(y);
    if(y > x && y >=-x)//오른쪽
        return pow((2*n+1),2) - 6*n - (n+x);
    if(y <-x && y >= x) //위쪽
        return pow((2*n+1),2) - 4*n - (n+y);
    if(y < x && y <=-x) //왼쪽
        return pow((2*n+1),2) - 2*n - (n-x);
    if(y >-x && y <= x) //아래쪽
        return pow((2*n+1),2) - 0*n - (n-y);
    return 1;
}

int main(){
    int r1,c1,r2,c2;
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    int n, width = 0;

    int max_v = max(returnValue(r1,c1),returnValue(r2,c1));
    max_v = max(max_v,returnValue(r1,c2));
    max_v = max(max_v,returnValue(r2,c2));

    while(max_v != 0){
        max_v/=10;
        width+=1;
    }
    for(int i = r1; i<= r2; i++){
        for(int j = c1; j<= c2; j++){
            
            printf("%*d ",width,returnValue(i,j));
        }
        printf("\n");
    }
}