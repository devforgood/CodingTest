#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;



int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    unordered_map<string, int> map;
    for (auto c : clothes)
        map[c[1]] += 1;

    for (auto m : map)
        answer *= (m.second + 1);


    return answer - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        vector<vector<string>> clothes;
        for (int j = 0; j < n; ++j)
        {
            string name, kind;
            cin >> name >> kind;
            vector<string> c;
            c.push_back(name);
            c.push_back(kind);
            clothes.push_back(c);
        }
        cout << solution(clothes) << "\n";
    }

}

