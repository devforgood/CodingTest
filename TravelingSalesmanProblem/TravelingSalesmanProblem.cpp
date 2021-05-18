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
		// 현재 논드에서 시작 노드로 돌아가기 위한 비용
		if (arr[x][0] == 0)
			return 1e9; // 돌아가는길이 없다면 해당 길은 제외되도록한다.
		else
			return arr[x][0];
	}

	// 이전에 방문했던 경로면 과거 데이터를 리턴
	if (dp[x][visited] != -1)
		return dp[x][visited];

	// 가장 적은 값을 찾기위해 최대값으로 초기화
	dp[x][visited] = 1e9;
	for (int i = 0; i < n; i++)
	{
		// 이전 방문 경로 스킵
		if ((visited & (1 << i)) == (1<<i))
			continue;

		// 갈수 있는 경로인지 확인
		if (arr[x][i] == 0)
			continue;

		// 최단 경로로 재귀호출
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
