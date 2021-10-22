#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>

using namespace std;

const int INF = 9e8;
map<int, vector<pair<int, int> > > edge;
int dist[20001];
int N, E;


int dijkstra(int start, int end)
{
	for (int i = 0; i <= N; ++i)
		dist[i] = INF;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (pq.empty() == false)
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (current == end)
			break;

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

	cin >> N >> E;



	int a, b, c;
	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	int answer = 0;
	answer += dijkstra(1, v1);
	answer += dijkstra(v1, v2);
	answer += dijkstra(v2, N);

	int answer2 = 0;
	answer2 += dijkstra(1, v2);
	answer2 += dijkstra(v2, v1);
	answer2 += dijkstra(v1, N);

	if (answer > answer2)
		answer = answer2;

	if (answer >= INF || answer < 0)
		cout << "-1\n";
	else
		cout << answer << "\n";

}
