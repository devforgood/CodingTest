#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int INF = 9e8;
map<int, vector<pair<int, int> > > edge;
int dist[1001] = { 0, };
int trace[1001] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i <= n; ++i)
        dist[i] = INF;

    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        edge[a].push_back({ b, c });
    }

    int s, e;
    cin >> s >> e;

    priority_queue<pair<int, int > > pq;
    pq.push({ 0, s });
    dist[s] = 0;

    while (pq.empty() == false)
    {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (dist[cur] < distance)
            continue;

        for (auto node : edge[cur])
        {
            int next = node.first;
            int nextDistance = node.second + distance;

            if (nextDistance< dist[next])
            {
                dist[next] = nextDistance;
                pq.push({ -nextDistance, next });

                trace[next] = cur;
            }
        }
    }

    cout << dist[e] << "\n";

    vector<int> answer;
    for (; e != s; e = trace[e])
        answer.push_back(e);
    answer.push_back(s);


    cout << answer.size() << "\n";
    for (int i = answer.size()-1;i>=0; --i)
        cout << answer[i] << " ";

}