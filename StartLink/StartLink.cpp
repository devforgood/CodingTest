#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visited[20] = { false, };
int board[20][20] = { 0, };
int arr[20] = { 0, };
int min_value = 9e8;

void func(int num, int cnt)
{
	if (cnt == n/2)
	{
		vector<int> other;
		for (int i = 0; i < n; ++i)
			if (visited[i] == false)
				other.push_back(i);

		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = i + 1; j < n / 2; ++j)
			{
				sum1 += board[arr[i]][arr[j]] + board[arr[j]][arr[i]];
				sum2 += board[other[i]][other[j]] + board[other[j]][other[i]];
			}
		}

		min_value = min(min_value, abs(sum1 - sum2));

		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			arr[cnt] = i;
			func(i+1, cnt + 1);
			visited[i] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}
	
	func(0, 0);

	cout << min_value << "\n";
}
