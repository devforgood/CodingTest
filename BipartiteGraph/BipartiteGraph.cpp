#include <iostream>
#include <queue>
#include <memory.h>
#include <map>

using namespace std;



int visited[20001];
map<int, map<int, int> > graph;

int v  = 0, e = 0;

bool bfs(int index)
{
    queue<int> q;
    q.push(index);
    visited[index] = 1;

    while (q.empty() == false)
    {
        index = q.front();
        q.pop();
 
        for (auto itr : graph[index])
        {
            int i = itr.first;

            if (visited[i] == visited[index])
                return false;

            if (visited[i] != 0)
                continue;

            q.push(i);
            visited[i] = visited[index]==1?2:1;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    while (k--)
    {
        cin >> v >> e;

        int a, b;
        for (int i = 0; i < e; ++i)
        {
            cin >> a >> b;

            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        bool isYes = true;
        for (int i=1;i<=v;++i)
        {
            if (visited[i] == 0)
            {
                if (bfs(i) == false)
                {
                    isYes = false;
                    break;
                }
            }
        }

        if (isYes)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

        graph.clear();


        memset(visited, 0, sizeof(visited));

    }
}
