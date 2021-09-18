#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;


int n;
int arr[2000] = { 0, };
int dp[2000][2000] = { 0, };


int func(int s, int e)
{
	if (s>=e)
	{
		return 1;
	}

	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}

	dp[s][e] = 0;
	if (arr[s] == arr[e])
	{
		dp[s][e] = func(s + 1, e - 1);
	}

	return dp[s][e];
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >>  n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	int m;
	cin >> m;

	int s, e;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		cout << func(s-1, e-1) << "\n";
	}

}

