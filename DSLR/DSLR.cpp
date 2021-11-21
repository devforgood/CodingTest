#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int getNext(int i, int v)
{
    int ret = 0;
	if (i == 0)
	{
        ret = (2 * v) % 10000;
	}
	else if (i == 1)
	{
        ret = (v - 1) < 0 ? 9999 : v - 1;
	}
	else if (i == 2)
	{
        ret = (v % 1000) * 10 + v / 1000;
    }
    else
    {
        ret = (v % 10) * 1000 + (v / 10);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string cmd = "DSLR";


    int t;

    cin >> t;

    while (t--)
    {
        queue<pair<int, string> > q;
        int a, b;
        cin >> a >> b;

        int visited[10000] = { 0, };

        q.push({ a, "" });
        visited[a] = 1;

        string answer;
        while (q.empty() == false)
        {
            int v = q.front().first;
            answer = q.front().second;
            q.pop();

            if (v == b)
                break;

            for (int i = 0; i < 4; ++i)
            {
                int nv = getNext(i, v);

                if (visited[nv] == 0)
                {
                    q.push({ nv, answer + cmd[i] });
                    visited[nv] = visited[v] + 1;
                }
            }
        }

        cout << answer << "\n";
    }




}
