
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{


    TEST_CLASS(Rank)
    {
    public:

        int solution(int n, vector<vector<int>> results) {
            int answer = 0;
            vector<int> graph[200 + 1];
            vector<int> graph_reverse[200 + 1];
            for (int i = 0; i < results.size(); ++i)
            {
                graph[results[i][1]].push_back(results[i][0]);
                graph_reverse[results[i][0]].push_back(results[i][1]);
            }

            stack<int> stack;
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
            {
                bool visited[200 + 1] = { false, };
                stack.push(i);
                cnt = 1;
                while (stack.empty() == false)
                {
                    int node = stack.top();
                    stack.pop();
                    for (auto j : graph[node])
                    {
                        if (visited[j] == true)
                            continue;

                        visited[j] = true;
                        stack.push(j);
                        ++cnt;
                    }
                }

                stack.push(i);
                while (stack.empty() == false)
                {
                    int node = stack.top();
                    stack.pop();
                    for (auto j : graph_reverse[node])
                    {
                        if (visited[j] == true)
                            continue;

                        visited[j] = true;
                        stack.push(j);
                        ++cnt;
                    }
                }
                if (cnt == n)
                    ++answer;
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(2, solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}}));


        }



    };
}
