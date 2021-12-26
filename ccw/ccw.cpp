#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[3][2];
	for (int i = 0; i < 3; ++i)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	if ((arr[1][0] - arr[0][0]) * (arr[2][1] - arr[0][1]) > (arr[1][1] - arr[0][1]) * (arr[2][0] - arr[0][0]))
		cout << 1;
	else if ((arr[1][0] - arr[0][0]) * (arr[2][1] - arr[0][1]) < (arr[1][1] - arr[0][1]) * (arr[2][0] - arr[0][0]))
		cout << -1;
	else
		cout << 0;
}
