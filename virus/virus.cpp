#include <iostream>
#include <set>
#include <memory.h>
#include <queue>
#include <algorithm> 

using namespace std;

int n, m;
int graph[1001][1001];
bool visited[1001];

void dfs(int index)
{
    visited[index] = true;

    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] || graph[index][i] != 1)
            continue;

        dfs(i);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(1);

    cout << std::count(visited, visited+n+1, true) -1 << "\n";
}
