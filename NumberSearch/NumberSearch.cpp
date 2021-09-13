#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;


int arr[100000] = { 0, };



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, m;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];


	sort(arr, arr + n);

	cin >> m;
	int num;
	for (int i = 0; i < m; ++i)
	{
		cin >> num;

		bool find = false;
		int start = 0;
		int end = n-1;
		int index = 0;
		while (start <= end)
		{
			index = (end + start) / 2;
			if (arr[index] == num)
			{
				find = true;
				break;
			}
			else if (arr[index] > num)
			{
				end = index-1;
				if (end < 0)
					break;
			}
			else
			{
				start = index+1;
				if (start >= n)
					break;
			}
		}

		if (find)
			cout << "1\n";
		else
			cout << "0\n";
	}
}
