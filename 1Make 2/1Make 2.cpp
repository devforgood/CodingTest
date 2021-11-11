#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;


int dp[1000000 + 1];
int trace[1000000 + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[1] = 0;
    trace[1] = -1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        trace[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            trace[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            trace[i] = i / 3;
        }
    }

    cout << dp[n] << "\n";

    for(;n != -1;n = trace[n])
            cout << n << " ";
        

 
}
