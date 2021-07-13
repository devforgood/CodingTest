#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[301];
int dp[301];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}

	cout << dp[n];

}