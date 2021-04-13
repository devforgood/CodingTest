
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


    TEST_CLASS(Network)
    {
    public:

        int dfs(vector<vector<int>> computers, int j, int n, bool visited[])
        {
            visited[j] = true;
            int cnt = 1;

            for (int k = 0; k < n; ++k)
			{
                if (j == k)
                    continue;

				if (computers[j][k] == 0)
					continue;
                
                if (visited[k] == true)
                    continue;

				cnt += dfs(computers, k, n, visited);

			}
            return cnt;
        }

        int solution(int n, vector<vector<int>> computers) {
            int answer = n;
            bool visited[200 + 1] = { 0, };


            int cnt;
            for (int i = 0; i < n; ++i)
            {
                if (visited[i] == true)
                    continue;

                visited[i] = true;

                cnt = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (i == j)
                        continue;

                    if (visited[j] == true)
                        continue;

                    if (computers[i][j] == 0)
                        continue;
                    
                    cnt += dfs(computers, j, n, visited);
                }

                answer -= cnt;
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(1, solution(3, { {1, 1, 0}, {1, 1, 1}, {0, 1, 1} }));
            Assert::AreEqual(2, solution(3, { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} }));
 

        }



    };
}
