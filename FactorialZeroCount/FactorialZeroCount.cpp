// FactorialZeroCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;

    int answer = 0;
    while (n >= 5)
    {
        answer += n / 5;
        n = n / 5;
    }

    cout << answer;
}
