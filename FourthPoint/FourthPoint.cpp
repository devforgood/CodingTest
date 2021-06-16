#include <iostream>

using namespace std;

int main()
{
	int matrix[4][2];

	for(int i=0;i<3;++i)
		cin >> matrix[i][0] >> matrix[i][1];

	for (int i = 0; i < 3; ++i)
	{
		bool find_x = false;
		bool find_y = false;
		for (int j = 0; j < 3; ++j)
		{
			if (i == j)
				continue;

			if (matrix[i][0] == matrix[j][0])
				find_x = true;
			if (matrix[i][1] == matrix[j][1])
				find_y = true;
		}
		if (find_x==false)
			matrix[3][0] = matrix[i][0];
		if (find_y==false)
			matrix[3][1] = matrix[i][1];
	}

	cout << matrix[3][0] << " " << matrix[3][1];
}

