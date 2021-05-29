#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<char> char_set;
    int cnt = 0;
    bool is_valid = false;
    for (int i = 0; i < n; ++i)
    {
        char_set.clear();
        string str;
        cin >> str;
        is_valid = true;
        char last_char = str[0];
        char_set.insert(last_char);
        for (int j = 1; j < str.length(); ++j)
        {
            if (last_char != str[j])
            {
                if (char_set.find(str[j]) != char_set.end())
                {
                    is_valid = false;
                }
            }
            last_char = str[j];
            char_set.insert(last_char);
        }

        if (is_valid)
            ++cnt;
    }

    cout << cnt;
}