#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;


int arr[500000] = { 0, };


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

		int min = 0;
		int max = n-1;
		int mid = 0;
		int cnt = 0;

		while (min <= max)
		{
			mid = (max + min) / 2;
			if (arr[mid] == num)
			{
				++cnt;
				for (int j = mid+1; j <= max; ++j)
				{
					if (arr[j] != num)
						break;
					++cnt;
				}
				for (int j = mid -1; j >= min; --j)
				{
					if (arr[j] != num)
						break;
					++cnt;
				}

				break;
			}
			else if (arr[mid] < num)
			{
				min = mid + 1;
			}
			else
			{
				max = mid - 1;
			}
		}

		cout << cnt << " ";

	}
}

