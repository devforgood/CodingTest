#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <numeric>

using namespace std;

const int MAX = 1001;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int cost[MAX] = { 0, };
		int indegree[MAX] = { 0, };
		int answer[MAX] = { 0, };
		vector<int> arr[MAX];


		int n, k;
		cin >> n >> k;

		for (int i = 1; i <= n; ++i)
		{
			cin >> cost[i];
		}

		for (int i = 0; i < k; ++i)
		{
			int a, b;
			cin >> a >> b;

			arr[a].push_back(b);
			indegree[b]++;
		}

		int w;
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
				answer[i] = cost[i];
			}
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

			if (w == a)
				break;

			for (auto v : arr[a])
			{
				// 이전 경로에 모든 비용을 기록
				answer[v] = max(answer[v], answer[a] + cost[v]);
				if (--indegree[v] == 0)
				{
					q.push(v);
				}
			}


			

		}

		cout << answer[w] << "\n";
	}
}