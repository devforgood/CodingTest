#include <iostream>
#include <stack>
#include <string>

using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;

    stack<int> st;
    string cmd;
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            st.push(num);
        }
        else if(cmd == "pop")
        {
            if (st.empty())
                cout << "-1\n";
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << st.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << (st.empty() ? 1 : 0) << "\n";
        }
        else if (cmd == "top")
        {
            if (st.empty())
                cout << "-1\n";
            else
            {
                cout << st.top() << "\n";
            }
        }
    }




}
