#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9e8;
int dist[102][102];
int route[102][102];

void trace(int s, int e, vector<int>& answer)
{
	if (route[s][e] == 0)
	{
		answer.push_back(s);
		answer.push_back(e);
		return;
	}
	// 두 지점의 사이중 가장 비용이 적은 노드 기록
	// 반복적으로 두지점을 분할해가며 노드를 탐색한다
	trace(s, route[s][e], answer);
	answer.pop_back();
	trace(route[s][e], e, answer);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dist[i][j] = INF;

	int a, b, c;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	for (int i = 0; i <= n; ++i)
		dist[i][i] = 0;

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					// 두 지점의 사이중 가장 비용이 적은 노드 기록
					route[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dist[i][j] == INF || i==j)
			{
				cout << "0";
			}
			else
			{
				vector<int> answer;
				trace(i, j, answer);
				cout << answer.size() << " ";

				for (auto v : answer)
					cout << v << " ";
			}
			cout << "\n";
		}

	}

}
