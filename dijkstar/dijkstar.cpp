#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>

using namespace std;

const int INF = 9e8;
map<int, vector<pair<int, int> > > edge;
int dist[20001];
int visited[20001];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 0; i <= V; ++i)
		dist[i] = INF;

	int a, b, c;
	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b >> c;
		edge[a].push_back( { b, c } );
	}

	dist[K] = 0;
	// 힙 구조 이용
	priority_queue<pair<int, int> > pq;
	pq.push({ 0, K });

	while (pq.empty() == false)
	{
		int cur = pq.top().second;
		// 짧은 것이 먼저 오도록 음수화(-)합니다.
		int distance = -pq.top().first;

		pq.pop();

		// 최단 거리가 아닌 경우 스킵합니다.
		if (dist[cur] < distance)
			continue;

		for (auto node : edge[cur])
		{
			// 선택된 노드의 인접 노드
			int next = node.first;
			// 선택된 노들를 인접 노드로 거쳐서 가는 비용
			int nextDistance = node.second + distance;
			// 기존의 최소 비용보다 더 저력하다면 교체
			if (nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}



	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}


}