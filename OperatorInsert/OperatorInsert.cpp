#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums;
vector<int> operators;
vector<int> visited;
int min_value = 1000000000;
int max_value = -1000000000;

void func(int cnt, int value)
{
	if (cnt == n-1)
	{
		if (min_value > value)
			min_value = value;
		if (max_value < value)
			max_value = value;
		return;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		if (visited[i] != 0)
			continue;

		visited[i] = 1;
		switch (operators[i])
		{
		case 0:
			func(cnt + 1, value + nums[cnt + 1]);
			break;
		case 1:
			func(cnt + 1, value - nums[cnt + 1]);
			break;
		case 2:
			func(cnt + 1, value * nums[cnt + 1]);
			break;
		case 3:
			func(cnt + 1, value / nums[cnt + 1]);
			break;
		}
		visited[i] = 0;
	}
}

int main()
{
	int v;

	cin >> n;
	visited.resize(n - 1);
	std::fill(visited.begin(), visited.end(), 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		nums.push_back(v);
	}
	for (int i = 0; i < 4; ++i)
	{
		cin >> v;
		for(int j=0;j<v;++j)
			operators.push_back(i);
	}

	func(0, nums[0]);

	cout << max_value << '\n';
	cout << min_value << '\n';
}
