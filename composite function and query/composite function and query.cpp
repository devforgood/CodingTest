#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;

// log(500000)
long long dp[505050][22];



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> dp[i][0];
    }

    for (int j = 1; j < 22; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) 
    {
        long long n, x; 
        cin >> n >> x;

        for (int i = 0; i<22; i++) 
        {
            if (n & (1<<i)) 
                x = dp[x][i];
        }
        cout << x << "\n";
    }



}