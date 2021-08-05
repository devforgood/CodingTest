
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[10] = { 0, };
    cin >> n;


	pair<int, int> v;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; ++i)
	{
		cin >> v.first >> v.second;
		vec.push_back(v);
	}


	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		});

	int answer = 1;
	int end = vec[0].second;
	for (int i = 1; i < n; ++i)
	{
		if (end <= vec[i].first)
		{
			++answer;
			end = vec[i].second;
		}
	}


    cout << answer;

}
