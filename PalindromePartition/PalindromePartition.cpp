#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int n;
int dp[2502];
char arr[2502];
bool palindrome[2502][2502];



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> arr+1;

	n = strlen(arr+1);
	
	// 하나씩
	for (int i = 1; i <= n; ++i)
		palindrome[i][i] = true;
	
	// 인접한 두개 
	for(int i=1;i<n;++i)
		if(arr[i]==arr[i+1])
			palindrome[i][i+1] = true;

	int start;
	int end;
	// 세개 이상
	for (int i = 2; i < n; ++i)
	{
		for (start = 1;  start + i <= n; ++start)
		{
			end = start + i;

			if (arr[start] == arr[end] && palindrome[start + 1][end - 1] == true)
				palindrome[start][end] = true;
		}
	}

	// 앞에서 부터 팰린드롬 가능 여부 확인하여 뒤로 범위를 넓혀 가는 방식
	for (int end = 1; end <= n; ++end)
	{
		dp[end] = 9e8;
		for (start = 1; start <= end; ++start)
		{
			if (palindrome[start][end])
				dp[end] = min(dp[end], dp[start - 1] + 1);
		}
	}

	cout << dp[n];

    return 0;
}
