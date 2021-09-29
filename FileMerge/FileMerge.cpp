#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n;
    cin >> t;

    int arr[501] = { 0, };
    int sum[501] = { 0, };
    int dp[501][501] = { 0, };

    for (int i = 0; i < t; ++i)
    {
        cin >> n;

        for (int j = 1; j <= n; ++j)
        {
            cin >> arr[j];
            sum[j] = arr[j] + sum[j - 1];
        }

        memset(dp, 0, sizeof(dp));

        // 페이지의 간격
        for (int gap = 1; gap < n; ++gap)
        {
            // 시작 인덱스
            for (int start = 1; start+gap <= n; ++start)
            {
                int end = start + gap;
                dp[start][end] = 9e8;

                // 중간 인덱스
                for (int mid = start; mid < end; ++mid)
                {
                    // start에서 end 까지 합의 비용 sum[end] - sum[start-1] (이부분이 이해가 안가면 문제를 다시 살펴본다)
                    // 예)
                    // 1,1 + 2,5
                    // 1,2 + 3,5
                    // 1,3 + 4,5
                    // 1,4 + 5,5

                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start-1]);
                }
            }
        }

        cout << dp[1][n] << "\n";
    }





}
