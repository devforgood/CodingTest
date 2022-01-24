#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;


int answer[32001] = { 0, };
int degree[32001] = { 0, };
vector<int> arr[32001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, m;
	cin >> n >> m;

	int cnt = 1;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		degree[b] ++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] == 0)
			q.push(i);
	}


	for (int i = 1; i <= n; ++i)
	{
		if (q.empty())
		{
			// 사이클 발생
			break;
		}

		int a = q.front();
		q.pop();
		answer[i] = a;
		for (auto v : arr[a])
		{
			if (--degree[v] == 0)
				q.push(v);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << answer[i] << " ";
}