#include <iostream>
#include <set>
#include <memory.h>
#include <queue>
#include <algorithm> 
#include <vector>

using namespace std;

int t, n, m, k;
int graph[51][51];
bool visited[51][51];

int direction[4][2] =
{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i)
    {
        int x_to = x + direction[i][0];
        int y_to = y + direction[i][1];

        if (x_to >= 0 && x_to < n && y_to >= 0 && y_to < m
            && visited[x_to][y_to]==false && graph[x_to][y_to] == 1
            )
        {
            dfs(x_to, y_to);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m >> k;

        int x, y;
        for (int j = 0; j < k; ++j)
        {
            cin >> x >> y;
            graph[x][y] = 1;
        }

        int cnt = 0;
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                if (visited[x][y] || graph[x][y] == 0)
                    continue;

                ++cnt;
                dfs(x, y);
            }
        }
        cout << cnt << "\n";

        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

    }
}
