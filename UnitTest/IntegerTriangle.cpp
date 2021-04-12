
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


    TEST_CLASS(IntegerTriangle)
    {
    public:

        vector<vector<int>> dp;

        int dfs(vector<vector<int>> triangle, int i, int j)
        {
            if (triangle.size() == i + 1)
                return triangle[i][j];


            if (dp[i][j] != -1)
                return dp[i][j];

			int left = dfs(triangle, i + 1, j);
			int right = dfs(triangle, i + 1, j + 1);


            int value = triangle[i][j] + std::max(left, right);
            dp[i][j] = value;

            return value;
        }

        int solution2(vector<vector<int>> triangle) {
            int answer = 0;
            
            for (int i=0;i<triangle.size()-1;++i)
            {
                dp.push_back(vector<int>());
                for (int j=0;j<triangle[i].size();++j)
                {
                    dp[i].push_back(-1);
                }
            }

            answer = dfs(triangle, 0, 0);

            return answer;
        }

        int solution(vector<vector<int>> triangle) {
            int answer = 0;

            for (int i = triangle.size()-1; i > 0; --i)
            {
                for (int j = 0; j < triangle[i].size()-1; ++j)
                {
                    triangle[i - 1][j] += std::max(triangle[i][j], triangle[i][j + 1]);
                }
            }

            return triangle[0][0];
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(30, solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}} ));


        }



    };
}
