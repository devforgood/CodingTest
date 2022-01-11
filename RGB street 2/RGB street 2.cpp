#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_VALUE = 1000001;
int dp[1001][3];
int rgb[1001][3];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];

    }

    int answer = MAX_VALUE;

    // 시작이 r, g, b 중 하나를 선택하여 시도
    for (int j = 0; j < 3; ++j)
    {
        dp[1][0] = MAX_VALUE;
        dp[1][1] = MAX_VALUE;
        dp[1][2] = MAX_VALUE;
        dp[1][j] = rgb[1][j];



        for (int i = 2; i <= N; ++i)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + rgb[i][2];
        }

        dp[N][j] = MAX_VALUE;
        answer = min({ answer,  dp[N][0],  dp[N][1],  dp[N][2] });
    }


    cout << answer;
}