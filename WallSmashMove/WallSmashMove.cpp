#include <iostream>
#include <set>
#include <memory.h>
#include <queue>
#include <algorithm> 
#include <vector>

using namespace std;

int n, m;
char graph[1000][1000 + 1];
int visited[1000][1000][2];

int direction[4][2] =
{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

struct pos
{
    int x;
    int y;
    int state;
};

int bfs()
{

    visited[0][0][0] = 1;
    queue <pos> q;
    q.push({ 0, 0, 0 });

    int x, y, nx, ny;
    int state;
    while (q.empty() == false)
    {
        x = q.front().x;
        y = q.front().y;
        state = q.front().state;

        if (x == n - 1 && y == m - 1)
            return visited[x][y][state];


        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nx = x + direction[i][0];
            ny = y + direction[i][1];

            if (nx < 0 || ny < 0)
                continue;

            if (nx >= n || ny >= m)
                continue;

            // 벽을 부셨을때와 부시지않았을때 이동 경로 둘다 보관이 필요함
            // 벽을 한번만 부실수 있으므로 visited 체크를 따로 하지 않는다.
            
            // 벽을 부수고 이동
            if (graph[nx][ny] == '1' && state == 0)
            {
				q.push({ nx, ny, state+1 });
				visited[nx][ny][state+1] = visited[x][y][state] + 1;
            }

            // 벽이 없고 그냥 이동
            if (graph[nx][ny] == '0' && visited[nx][ny][state] == 0)
            {
                q.push({ nx, ny, state });
                visited[nx][ny][state] = visited[x][y][state] + 1;
            }
        }
    }

    return -1;
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

    cout << bfs();
}
