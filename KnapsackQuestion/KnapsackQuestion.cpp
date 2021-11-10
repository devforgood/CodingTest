#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

long long n, c;
long long arr[30] = { 0, };

void dfs(int start, int end, long long sum, vector<long long> & v)
{
    if (start > end)
    {
        // 마지막 도달
        v.push_back(sum);
    }
    else
    {
        // 포함 안하는 경우
        dfs(start + 1, end, sum, v);
        // 포함 하는 경우
        dfs(start + 1, end, sum + arr[start], v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<long long> l, r;
    dfs(0, n / 2, 0, l);
    dfs(n / 2+1, n-1, 0, r);
    sort(r.begin(), r.end());

    long long answer = 0;
    // 이분탐색
    for (int i = 0; i < l.size(); ++i)
        answer += upper_bound(r.begin(), r.end(), c - l[i]) - r.begin();

    cout << answer << "\n";
}
