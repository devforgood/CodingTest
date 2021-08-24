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


    for (int i = 1; i < n; ++i)
    {
        int gcd = GCD(arr[0], arr[i]);
        cout << arr[0] / gcd << "/" << arr[i] / gcd << "\n";
    }

   
}

