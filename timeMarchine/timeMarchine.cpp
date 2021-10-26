#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


const int INF = 9e8;
map<int, vector<pair<int, int> > > edge;
long long dist[502];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
	}

	for (int i = 0; i <= N; ++i)
		dist[i] = INF;

	bool is_circle = false;
	dist[1] = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			for (auto & node : edge[j])
			{
				if (dist[j] != INF && dist[node.first] > node.second + dist[j])
				{
					dist[node.first] = node.second + dist[j];

					if (i == N)
						is_circle = true;
				}
			}
		}
	}

	if (is_circle)
		cout << "-1\n";
	else
		for (int i = 2; i <= N; ++i)
			if(dist[i]==INF)
				cout << "-1\n";
			else
				cout << dist[i]<< "\n";

  
}
