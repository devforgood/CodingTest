#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;


struct pos
{
    int x;
    int y;
};

int direction[8][2] =
{
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {1, 2},
    {-1, 2},
    {-2, 1},
};

int visited[300][300];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, l;
    int sx, sy, ex, ey, nx, ny;

    cin >> t;
    while (t--)
    {
        cin >> l;

        cin >> sx >> sy >> ex >> ey;

        memset(visited, 0, sizeof(visited));

        queue<pos> q;
        q.push({ sx, sy });
        visited[sx][sy] = 1;

        while (q.empty() == false)
        {
            int x = q.front().x;
            int y = q.front().y;

            if (x == ex && y == ey)
                break;

            q.pop();

            for (int i = 0; i < 8; ++i)
            {
                nx = x + direction[i][0];
                ny = y + direction[i][1];

                if (nx < 0 || ny < 0 || nx >= l || ny >= l)
                    continue;
                
                if (visited[nx][ny] != 0)
                    continue;

                q.push({ nx, ny });
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
        cout << visited[ex][ey]-1 << "\n";

    }


   
}
