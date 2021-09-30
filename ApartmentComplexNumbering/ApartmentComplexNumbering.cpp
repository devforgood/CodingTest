#include <iostream>
#include <set>
#include <memory.h>
#include <queue>
#include <algorithm> 
#include <vector>

using namespace std;

int n, m;
char graph[25][25+1];
bool visited[25][25];

int direction[4][2] =
{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};


int dfs(int x, int y)
{
    int cnt = 1;
    visited[x][y] = true;

    int next_x;
    int next_y;
    for (int i = 0; i < 4; ++i)
    {
        next_x = x + direction[i][0];
        next_y = y + direction[i][1];

        if (visited[next_x][next_y] || graph[next_x][next_y] != '1')
            continue;

        cnt += dfs(next_x, next_y);
    }

    return cnt;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }
    

    vector<int> answer;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visited[i][j] || graph[i][j] != '1')
                continue;

            answer.push_back(dfs(i, j));
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << "\n";

}
