#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool vps(string bracket)
{
    stack<char> st;
    for (int i = 0; i < bracket.size(); ++i)
    {
        if (bracket[i] == ')')
        {
            if (st.empty())
            {
                return false;
            }
            st.pop();
        }
        else
            st.push(bracket[i]);
    }
    return st.empty();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;

    
    for (int i = 0; i < n; ++i)
    {
        string bracket;
        cin >> bracket;
        if (vps(bracket))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}
