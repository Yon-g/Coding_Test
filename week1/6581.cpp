/*
알고리즘 : 구현, 문자열
시간복잡도 : O(N)
공간복잡도 : O(1)

접근 과정 :
    1) 문자열 종료 판단, 입력 경우 나누기, 띄어쓰기

풀이 시작 시간 : 2025.09.24 / 23:20
풀이 종료 시간 : 2025.09.24 / 23:42
*/

#include <iostream>

using namespace std;

int main(){
    int len = 0;

    string word;

    while(cin >> word){
        if(word == "<br>"){
            len = 0;
            cout << "\n";
        }
        else if (word == "<hr>")
        {
            if(len){
                cout << "\n";
            }
            cout << "--------------------------------------------------------------------------------";
            len = 0;
            cout << "\n";
        }
        else{
            if(len + word.length() + 1 > 80){
                cout << "\n";
                len = 0;
            }
            if(len){
                cout << " ";
                len+=1;
            }
            cout << word;
            len+= word.length();
        }
    }
}