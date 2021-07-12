#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	vector<int> triangle[500];
	int n;

	cin >> n;

	int v;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cin >> v;
			triangle[i].push_back(v);
		}
	}

	for (int i = n-1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			triangle[i - 1][j] += triangle[i][j] > triangle[i][j + 1] ? triangle[i][j] : triangle[i][j + 1];
		}
	}
	
	cout << triangle[0][0];

}