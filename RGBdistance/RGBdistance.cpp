#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][3];
int main() {
    int N;
    int rgb[3];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> rgb[0] >> rgb[1] >> rgb[2];
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + rgb[2];
    }
    cout << min(dp[N][2], min(dp[N][0], dp[N][1]));
}