#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <memory.h>
#include <limits.h>

using namespace std;

int n = 0;
int arr[128][128] = { 0, };
int white_count = 0;
int blue_count = 0;

int func(int start_x, int start_y, int end_x, int end_y, int size)
{
	if (size == 0)
		return arr[start_x][start_y];

	int values[4];
	values[0] = func(start_x, start_y, start_x + size, start_y + size, size / 2);
	values[1] = func(start_x, start_y + size, start_x + size, end_y, size / 2);
	values[2] = func(start_x + size, start_y, end_x, start_y + size, size / 2);
	values[3] = func(start_x + size, start_y + size, end_x, end_y, size / 2);

	if (values[0] == values[1] && values[0] == values[2] && values[0] == values[3])
		return values[0];
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if(values[i]== 0)
				++white_count;
			else if(values[i]==1)
				++blue_count;
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int val = func(0, 0, n, n, n / 2);
	if(val == 0)
		++white_count;
	else if (val == 1)
		++blue_count;

	cout << white_count << "\n";
	cout << blue_count << "\n";

}
