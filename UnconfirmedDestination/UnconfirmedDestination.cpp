#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9e8;
map<int, vector<pair<int, int> > > edge;
int dist[20001];
int  n, m, t;
int s, g, h;


int dijkstra(int start, int end)
{
	for (int i = 0; i <= n; ++i)
		dist[i] = INF;

	priority_queue<pair<int, int> > pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (pq.empty() == false)
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		if (current == end)
			break;

		pq.pop();

		if (dist[current] < distance)
			continue;

		for (auto node : edge[current])
		{
			int next = node.first;
			int nextDistance = node.second + distance;

			if (dist[next] > nextDistance)
			{
				dist[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}

	return dist[end];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		edge.clear();
		int a, b, c;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			edge[a].push_back({ b, c });
			edge[b].push_back({ a, c });
		}

		vector<int> destinations;
		int destination;
		for (int i = 0; i < t; ++i)
		{
			cin >> destination;

			int full_cost = dijkstra(s, destination);
			if (full_cost == dijkstra(s, g) + dijkstra(g, h) + dijkstra(h, destination)
				|| full_cost == dijkstra(s, h) + dijkstra(h, g) + dijkstra(g, destination))
			{
				destinations.push_back(destination);
			}
		}

		sort(destinations.begin(), destinations.end());

		for (int i = 0; i < destinations.size(); ++i)
			cout << destinations[i] << " ";
		cout << "\n";
	}

}
