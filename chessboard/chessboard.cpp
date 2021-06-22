#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;
	int answer = 8*8;
	char board[50][51];

	for (int i = 0; i < n; ++i)
		cin >> board[i];

	for (int i = 0; i + 7 < n; ++i)
	{
		for (int j = 0; j + 7 < m; ++j)
		{
			int b_count = 0;
			int w_count = 0;
			char b_start = 'B';
			char w_start = 'W';
			for (int x = i; x < i + 8; ++x)
			{
				for (int y = j; y < j + 8; ++y)
				{
					if (board[x][y] != b_start)
						++b_count;

					if (board[x][y] != w_start)
						++w_count;

					b_start = b_start == 'W' ? 'B' : 'W';
					w_start = w_start == 'W' ? 'B' : 'W';
				}
				b_start = b_start == 'W' ? 'B' : 'W';
				w_start = w_start == 'W' ? 'B' : 'W';
			}

			answer = min(answer, min(b_count, w_count));

		}
	}


	cout << answer;
}

