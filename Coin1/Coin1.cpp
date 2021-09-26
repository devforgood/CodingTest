#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;


int n, k;
int arr[100] = { 0, };
int dp[10000 + 1];

/*
Dynamic Programming으로 접근한다.

첫 번째 동전만 사용하여 각 k값 마다 가능한 경우의 수를 찾는다.

첫 번째~두 번째 동전만 사용하였을 때, 각k 값 마다 가능한 경우의 수를 찾는다.이 때, 첫 번째 동전만 사용해서 구했던 경우의 수를 활용한다.

첫 번째~n 번째 동전을 사용하였을 때까지 반복한다.

D(i, k) =
		k   0   1   2   3   4   5   6   7   8   9   10
c(0)    [0] 1   0   0   0   0   0   0   0   0   0   0
c(1)    [1] 1   1   1   1   1   1   1   1   1   1   1
c(2)    [2] 1   1   2   2   3   3   4   4   5   5   6
c(3)    [5] 1   1   2   2   3   4   5   6   7   8   10


*/


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];


	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
		{
			if (j - arr[i] >= 0)
			{
				dp[j] += dp[j - arr[i]];
			}
		}
	}

	cout << dp[k];
}

