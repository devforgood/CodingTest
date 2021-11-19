﻿#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[100001];
int trace[100001];

int getNext(int i, int v)
{
    if (i == 0)
        return v - 1;
    else if (i == 1)
        return v + 1;
    else
        return v * 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    queue<int> q;
    int n, k;
    cin >> n >> k;

    q.push(n);
    visited[n] = 1;

    while (q.empty() == false)
    {
        int v = q.front();
        q.pop();

        if (v == k)
            break;

        for (int i = 0; i < 3; ++i)
        {
            int nv = getNext(i, v);

            if (nv >= 0 && nv < 100001 && visited[nv] == 0)
            {
                q.push(nv);
                visited[nv] = visited[v] + 1;
                trace[nv] = v;
            }
        }

    }

    cout << visited[k] - 1 << "\n";

    vector<int> answer;
    for (; k != n; k = trace[k])
    {
        answer.push_back(k);
    }
    answer.push_back(n);

    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << " ";
}
