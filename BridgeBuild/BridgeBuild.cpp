#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

unsigned long long factorial(int num, int start = 2)
{
    long long result = 1;
    for (int i = start; i <= num; ++i)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, k;
        cin >> k >> n;

        int a, b;
        if (k > n - k)
        {
            a = k;
            b = n - k;
        }
        else
        {
            a = n - k;
            b = k;
        }


        cout << factorial(n, a + 1) / (factorial(b)) << "\n";
    }
}

