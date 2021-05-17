// TravelingSalesmanProblem.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int n;
int arr[16][16];
int dp[16][1 << 16];

int dfs(int x, int visited)
{
	if (visited == (1 << n) - 1)
	{
		if (arr[x][0] == 0)
			return 1e9;
		else
			return arr[x][0];
	}

	if (dp[x][visited] != -1)
		return dp[x][visited];

	dp[x][visited] = 1e9;
	for (int i = 0; i < n; i++)
	{
		if ((visited & (1 << i)) == (1<<i))
			continue;

		if (arr[x][i] == 0)
			continue;

		dp[x][visited] = min(dp[x][visited], dfs(i, visited | (1 << i)) + arr[x][i]);
	}
	return dp[x][visited];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));

	int answer = dfs(0, 1);

	cout << answer;
}
