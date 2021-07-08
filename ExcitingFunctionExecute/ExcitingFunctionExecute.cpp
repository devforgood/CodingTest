// ExcitingFunctionExecute.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tuple>
#include <map>

using namespace std;
map<tuple<int, int, int>, int> dp;

int w(int a, int b, int c)
{
    auto itr = dp.find(make_tuple(a, b, c));
    if (itr != dp.end())
        return itr->second;

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
    {
        int v = w(20, 20, 20);
        dp[make_tuple(20, 20, 20)] = v;
        return v;
    }

    if (a < b && b < c)
    {
        int v1 = w(a, b, c - 1);
        dp[make_tuple(a, b, c - 1)] = v1;

        int v2 = w(a, b - 1, c - 1);
        dp[make_tuple(a, b - 1, c - 1)] = v2;

        int v3 = w(a, b - 1, c);
        dp[make_tuple(a, b - 1, c)] = v3;

        return  v1 + v2 - v3;
    }

    int v1 = w(a - 1, b, c);
    dp[make_tuple(a - 1, b, c)] = v1;

    int v2 = w(a - 1, b - 1, c);
    dp[make_tuple(a - 1, b - 1, c)] = v2;

    int v3 = w(a - 1, b, c - 1);
    dp[make_tuple(a - 1, b, c - 1)] = v3;

    int v4 = w(a - 1, b - 1, c - 1);
    dp[make_tuple(a - 1, b - 1, c - 1)] = v4;

    return v1 + v2 + v3 - v4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << " \n";
    }

}
