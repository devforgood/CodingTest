#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int dp[1000001] = { 0, };

// 이상하게 재귀호출을 생각함
int func(int i, int cnt)
{
	if (i == 1)
	{
		return cnt;
	}

	if (dp[i] != 0)
		return dp[i] + 1;

	int min_count = func(i - 1, cnt + 1);

	if (i % 3 == 0)
		min_count = min(min_count, func(i / 3, cnt + 1));
	if (i % 2 == 0)
		min_count = min(min_count, func(i / 2, cnt + 1));
	
	dp[i] = min_count;

	return min_count;
}

int arr[1000001] = { 0, };

int main()
{
	cin >> n;

	//for (int i = 1; i <= n; ++i)
	//	func(i, 0);


	// 탑다운 방식으로 간단하게 풀이가 가능
	arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
	}


	cout << arr[n];

}