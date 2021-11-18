#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

struct pos
{
    int x;
    int y;
    
    int dist(pos & other)
    {
        return abs(x - other.x) + abs(y - other.y);
    }
};

int n, w;
int dp[1001][1001] = { 0, };
pos path_a[1001] = { 0, };
pos path_b[1001] = { 0, };

int dfs(int a, int b)
{
    if (a == w || b == w)
        return 0;
    
    if (dp[a][b] != -1)
        return dp[a][b];

    int next = max(a, b) + 1;

    int next_a = dfs(next, b) + path_a[a].dist(path_a[next]);
    int next_b = dfs(a, next) + path_b[b].dist(path_b[next]);

    dp[a][b] = min(next_a, next_b);

    return dp[a][b];
}

void trace(int a, int b)
{
    if (a == w || b == w)
        return;

    int next = max(a, b) + 1;
    int next_a = dfs(next, b) + path_a[a].dist(path_a[next]);
    int next_b = dfs(a, next) + path_b[b].dist(path_b[next]);

    if (next_a > next_b)
    {
        cout << 2 << "\n";
        trace(a, next);
    }
    else
    {
        cout << 1 << "\n";
        trace(next, b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> w;

    path_a[0] = { 1, 1 };
    path_b[0] = { n, n };
    for (int i = 1; i <= w; ++i)
    {
        cin >> path_a[i].x >> path_a[i].y;
        path_b[i] = path_a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << "\n";

    trace(0, 0);
} 