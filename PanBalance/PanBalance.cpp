#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;


int n;
int arr[30] = { 0, };
bool dp[31][30*500+1];


void func(int i, int w)
{
	if (i > n || dp[i][w] == true)
		return;

	dp[i][w] = true;

	// 추에 무게를 더한 경우
	func(i + 1, w + arr[i]);
	// 추에 무게를 뺀 경우
	func(i + 1, abs(w - arr[i]));
	// 추을 올리지 않은 경우
	func(i + 1, w);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	memset(dp, false, sizeof(dp));
	func(0, 0);

	int m;
	cin >> m;

	int w;
	for (int i = 0; i < m; ++i)
	{
		cin >> w;

		if (w > (30 * 500) || dp[n][w] == false)
			cout << "N ";
		else
			cout << "Y ";
	}

}

