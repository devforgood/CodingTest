#include <iostream>
#include <set>
#include <memory.h>
#include <queue>
#include <algorithm> 
#include <vector>

using namespace std;

int n, m, h;
int graph[100][100][100];

int direction[6][3] =
{
    {0, 1, 0},
    {0, 0, 1},
    {0, -1, 0},
    {0, 0, -1},
    {1, 0, 0},
    {-1, 0, 0},
};

struct pos
{
    int z;
    int x;
    int y;
};

queue <pos> q;


int bfs()
{
    int x, y, z, nx, ny, nz;
    while (q.empty() == false)
    {
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;


        q.pop();
        for (int i = 0; i < 6; ++i)
        {
            nz = z + direction[i][0];
            nx = x + direction[i][1];
            ny = y + direction[i][2];

            if (nx < 0 || ny < 0 || nz <0 || nx >= n || ny >= m || nz >= h)
                continue;

            if (graph[nz][nx][ny] != 0)
                continue;

            graph[nz][nx][ny] = graph[z][x][y] + 1;

            q.push({ nz, nx, ny });
        }
    }

    int answer = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                if (graph[i][j][k] == 0)
                {
                    return -1;
                }
                if (answer < graph[i][j][k])
                    answer = graph[i][j][k];
            }
        }
    }

    return answer - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1)
                    q.push({ i, j, k });
            }
        }
    }

    cout << bfs();
}
