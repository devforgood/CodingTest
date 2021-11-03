#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9e8;
int dist[102][10002];

class node
{
public:
	int v;
	int cost;
	int time;

	bool operator<(const node& c)const {

		return time > c.time;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;

		cin >> n >> m >> k;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				dist[i][j] = INF;
			}
		}

		map<int, vector<node> > graph;

		for (int i = 0; i < k; ++i)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			graph[a].push_back({ b, c, d });
		}

	
		priority_queue<node> pq;
		pq.push({ 1, 0, 0 });
		dist[1][0] = 0;

		while (pq.empty() == false)
		{
			auto cur = pq.top();
			pq.pop();

			if (dist[cur.v][cur.cost] < cur.time)
				continue;

			for (auto next : graph[cur.v])
			{
				int nextCost = next.cost + cur.cost;
				int nextTime = next.time + cur.time;

				if (nextCost > 10000)
					continue;

				if (dist[next.v][nextCost] > nextTime)
				{
					for (int j = nextCost + 1; j <= m; ++j)
					{
						if (dist[next.v][j] <= nextTime)
							break;
						dist[next.v][j] = nextTime;
					}

					dist[next.v][nextCost] = nextTime;
					pq.push({ next.v, nextCost, nextTime });
				}
			}

		}

		int answer = INF;
		for (int i = 0; i <= m; ++i)
		{
			answer = min(answer, dist[n][i]);
		}

		if (answer != INF)
			cout << answer << "\n";
		else
			cout << "Poor KCM\n";


	}


}

