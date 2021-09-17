#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;


int n, m;
int arr[500][500] = { 0, };
int dp[500][500] = { 0, };
int direction[4][2] =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};

int dfs(int x, int y)
{
	if (x == m-1 && y == n-1)
	{
		return 1;
	}

	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}

	int ret = 0;
	int next_x;
	int next_y;
	dp[x][y] = 0; // 이미 지나간곳은 0으로 초기화하여 다시 가지 않도록 한다
	for (int i = 0; i < 4; ++i)
	{
		next_x = x + direction[i][0];
		next_y = y + direction[i][1];

		if (next_x < 0 || next_x >= m
			|| next_y < 0 || next_y >= n)
			continue;

		if (arr[x][y] > arr[next_x][next_y])
		{
			dp[x][y] += dfs(next_x, next_y);
		}
	}

	return dp[x][y];
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> m >> n;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}

	dfs(0, 0);

	cout << dp[0][0] << "\n";
}

