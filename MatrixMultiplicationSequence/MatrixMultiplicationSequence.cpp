#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;

int arr[501][2] = { 0, };
int dp[501][501] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
	cin >> n;

	memset(dp, 0, sizeof(dp));

	for (int j = 1; j <= n; ++j)
	{
		cin >> arr[j][0] >> arr[j][1];
	}

	for (int i = 1; i < n; ++i)
	{
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	// 페이지의 간격
	for (int gap = 2; gap <= n; ++gap)
	{
		// 시작 인덱스
		for (int start = 1; start + gap <= n; ++start)
		{
			int end = start + gap;

			// 중간 인덱스
			for (int mid = start; mid < end; ++mid)
			{
				// 점화식
				int v= dp[start][mid] + dp[mid + 1][end] + arr[start][0] * arr[mid][1] * arr[end][1];

				if (dp[start][end]==0 || dp[start][end] > v )
				{
					dp[start][end] = v;
				}
			}
		}
	}

	cout << dp[1][n] << "\n";






}
