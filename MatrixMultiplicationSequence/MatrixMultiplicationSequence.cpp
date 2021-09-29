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

	// 페이지의 간격
	for (int gap = 1; gap < n; ++gap)
	{
		// 시작 인덱스
		for (int start = 1; start + gap <= n; ++start)
		{
			int end = start + gap;

			dp[start][end] = 9e8;

			// 중간 인덱스
			for (int mid = start; mid < end; ++mid)
			{
				// 점화식
				// 두개의 분할된 구간이 합이 arr[start][0] * arr[mid][1] * arr[end][1]
				// 이전 각각의 분할된 합이 dp[start][mid]과 dp[mid + 1][end] 저장 되어 있다.
				dp[start][end] = min(dp[start][end],  dp[start][mid] + dp[mid + 1][end] + arr[start][0] * arr[mid][1] * arr[end][1]);
			}
		}
	}

	cout << dp[1][n] << "\n";
}
