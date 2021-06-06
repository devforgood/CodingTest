#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int arr[15][15];
	for (int i = 0; i < 15; ++i)
		arr[0][i] = i;

	int sum = 0;
	for (int i = 1; i < 15; ++i)
	{
		sum = 0;
		for (int j = 1; j < 15; ++j)
		{
			sum += arr[i - 1][j];
			arr[i][j] = sum;
		}
	}
	
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; ++i)
	{
		int k, n;
		cin >> k >> n;

		cout << arr[k][n] << endl;
	}

}