
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

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(FarthestNode)
    {
    public:

 

        int solution(int n, vector<vector<int>> edge) {
            int answer = 0;

            vector<int> graph[20000 + 1];
            bool visited[20000 + 1] = { false };
            int depth[20000 + 1] = { 0 };

            for (auto vec : edge)
            {
                if (std::find(graph[vec[0]].begin(), graph[vec[0]].end(), vec[1]) == graph[vec[0]].end())
                    graph[vec[0]].push_back(vec[1]);
                if (std::find(graph[vec[1]].begin(), graph[vec[1]].end(), vec[0]) == graph[vec[1]].end())
                    graph[vec[1]].push_back(vec[0]);
            }

            queue<int> queue;
            queue.push(1);
            visited[1] = true;
            depth[1] = 1;
            int last_depth = 1;

            while (queue.empty() == false)
            {
                int cur = queue.front();
                queue.pop();

                for (int i = 0; i < graph[cur].size(); ++i)
                {
                    if (visited[graph[cur][i]] == true)
                        continue;

                    depth[graph[cur][i]] = depth[cur] + 1;
                    visited[graph[cur][i]] = true;
                    queue.push(graph[cur][i]);
                    if (last_depth != depth[graph[cur][i]])
                    {
                        last_depth = depth[graph[cur][i]];
                        answer = 0;
                    }
                    ++answer;

                }
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> edge = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };

            Assert::AreEqual(3, (int)solution(6, edge));
        }



    };
}
