// FibonacciFunction.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


int fib[41][2];

void fibonacci() 
{
    fib[0][0] = 1;
    fib[0][1] = 0;
    fib[1][0] = 0;
    fib[1][1] = 1;

    for (int i = 2; i <= 40; ++i)
    {
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
        fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;

    fibonacci();

    for (int i = 0; i < t; ++i)
    {
        cin >> n;

        cout << fib[n][0] << " " << fib[n][1] << "\n";
    }

}
