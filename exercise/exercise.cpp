#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9e8;
int dist[402][402];

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
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int answer = INF;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (i!=j && dist[i][j] != INF && dist[j][i] != INF)
				answer = min(answer, dist[i][j] + dist[j][i]);
	}

	if (answer == INF)
		cout << "-1\n";
	else
		cout << answer << "\n";

}
