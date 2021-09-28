#include <iostream>
#include <set>
#include <memory.h>
#include <queue>

using namespace std;

int n, m, v;
int graph[1001][1001];
bool visited[1001];

void dfs(int index)
{
    cout << index << " ";

    visited[index] = true;

    for (int i=1;i<=n;++i)
    {
        if (visited[i] || graph[index][i] != 1)
            continue;

        dfs(i);
    }
}

void bfs(int index)
{
    queue<int> q;
    q.push(index);
    visited[index] = true;

    while (q.empty() == false)
    {
        index = q.front();
        q.pop();
        cout << index << " ";

        for (int i=1;i<=n;++i)
        {
            if (visited[i] || graph[index][i]!=1)
                continue;

            q.push(i);
            visited[i] = true;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(v);

    cout << "\n";

    memset(visited, false, sizeof(visited));

    bfs(v);

}
