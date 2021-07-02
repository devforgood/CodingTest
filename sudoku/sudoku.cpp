#include <iostream>

using namespace std;

int board[9][9];


bool check(int x, int y)
{
	// check
	int visited_y = 0;
	int visited_x = 0;
	const int all_visited = 0b111111111;
	for (int i = 0; i < 9; ++i)
	{
		if (board[x][i] != 0)
		{
			if ((visited_y & (1 << board[x][i] - 1)) != 0)
				return false;

			visited_y |= (1 << board[x][i] - 1);
		}

		if (board[i][y] != 0)
		{
			if ((visited_x & (1 << board[i][y] - 1)) != 0)
				return false;

			visited_x |= (1 << board[i][y] - 1);
		}
	}

	int visited = 0;
	int start_x = (int)(x / 3) * 3;
	int start_y = (int)(y / 3) * 3;
	for (int i = start_x; i < start_x + 3; ++i)
	{
		for (int j = start_y; j < start_y + 3; ++j)
		{
			if (board[i][j] != 0)
			{
				if ((visited & (1 << board[i][j] - 1)) != 0)
					return false;

				visited |= (1 << board[i][j] - 1);
			}
		}
	}
	return true;

}


bool sudoku(int x, int y)
{
	if (x >= 9 || y >= 9)
		return false;

	if (board[x][y] == 0)
	{
		for (int i = 1; i <= 9; ++i)
		{
			board[x][y] = i;

			if (check(x, y))
			{
				if (x == 8 && y == 8)
					return true;

				if (sudoku(y != 8 ? x : x + 1, y != 8 ? y + 1 : 0))
					return true;
			}

			board[x][y] = 0;
		}

	}
	else
	{
		if (sudoku(y != 8 ? x : x + 1, y != 8 ? y + 1 : 0))
			return true;
	}
	return false;
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];
		}
	}

	sudoku(0, 0);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}