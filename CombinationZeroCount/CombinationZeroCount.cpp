
#include <iostream>

using namespace std;


long long FactorialZeroCount(int n, int divide)
{
    long long answer = 0;
    while (n >= divide)
    {
        answer += n / divide;
        n = n / divide;
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    cout << min(FactorialZeroCount(n, 5)-FactorialZeroCount(m, 5)-FactorialZeroCount(n-m, 5), FactorialZeroCount(n, 2) - FactorialZeroCount(m, 2) - FactorialZeroCount(n - m, 2));
}
