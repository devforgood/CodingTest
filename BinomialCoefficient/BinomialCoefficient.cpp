#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int factorial(int num)
{
    int result = 1;
    for (int i = 2; i <= num; ++i)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << factorial(n) / (factorial(k) * (factorial(n - k)));
}

