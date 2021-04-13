
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

        void dfs(vector<vector<int>> computers, int j, int n, bool visited[])
        {
 
            for (int k = 0; k < n; ++k)
			{
                if (j == k)
                    continue;

				if (computers[j][k] == 0)
					continue;
                
                if (visited[k] == true)
                    continue;

                visited[k] = true;


				dfs(computers, k, n, visited);
			}
        }

        int solution(int n, vector<vector<int>> computers) {
            int answer = 0;
            bool visited[200 + 1] = { 0, };

			for (int i = 0; i < n; ++i)
			{
				if (visited[i] == true)
					continue;

				visited[i] = true;
				++answer;

				dfs(computers, i, n, visited);
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
