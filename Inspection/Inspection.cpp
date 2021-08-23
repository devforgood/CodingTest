#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int GCD(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[100] = { 0, };
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int gcd = arr[1] - arr[0];
    for (int i = 2; i < n; ++i)
        gcd = GCD(gcd, arr[i] - arr[i - 1]);


    set<int> answer;
    for (int i = 2; i*i <= gcd; ++i)
    {
        if (gcd % i == 0)
        {
            answer.insert(i);
            answer.insert(gcd / i);
        }
    }
    answer.insert(gcd);

    for (auto v : answer)
    {
        cout << v << " ";
    }
    cout << "\n";
}

