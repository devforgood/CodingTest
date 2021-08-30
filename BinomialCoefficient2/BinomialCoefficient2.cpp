#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int arr[1001][1001] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == j || j == 0)
                arr[i][j] = 1;
            else
                arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
        }
    }

    cout << arr[n][k];

}

