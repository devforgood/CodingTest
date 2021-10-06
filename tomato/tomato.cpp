#include <iostream>
#include <set>
#include <memory.h>
#include <queue>
#include <algorithm> 
#include <vector>

using namespace std;

int n, m;
int graph[1000][1000];

int direction[4][2] =
{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};
queue < pair<int, int>> q;


int bfs()
{
    int x, y, nx, ny;
    while (q.empty() == false)
    {
        x = q.front().first;
        y = q.front().second;


        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            nx = x + direction[i][0];
            ny = y + direction[i][1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (graph[nx][ny] != 0)
                continue;

            graph[nx][ny] = graph[x][y] + 1;

            q.push(make_pair(nx, ny));
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (graph[i][j] == 0)
            {
                return -1;
            }
            if (answer < graph[i][j])
                answer = graph[i][j];
        }
    }

    return answer -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    cout << bfs();
}
