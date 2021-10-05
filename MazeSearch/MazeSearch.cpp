#include <iostream>
#include <set>
#include <memory.h>
#include <queue>
#include <algorithm> 
#include <vector>

using namespace std;

int n, m;
char graph[100][100 + 1];
int visited[100][100];

int direction[4][2] =
{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};


int bfs(int x, int y)
{
    visited[x][y] = 1;

    queue < pair<int, int>> q;
    q.push(make_pair(x, y));
    int nx;
    int ny;

    while (q.empty()==false)
    {
        x = q.front().first;
        y = q.front().second;
        
        if (x == n-1 && y == m-1)
            break;


        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nx = x + direction[i][0];
            ny = y + direction[i][1];

            if (nx < 0 || ny < 0)
                continue;

            if (nx > n || ny > m)
                continue;

            if (visited[nx][ny] != 0 || graph[nx][ny] != '1')
                continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return visited[x][y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    cout << bfs(0, 0);
}
