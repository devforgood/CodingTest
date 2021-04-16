
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


    TEST_CLASS(FunctionDevelop)
    {
    public:
        vector<int> solution(vector<int> progresses, vector<int> speeds) {
            vector<int> answer;

            queue<int> queue;
            for (int i=0;i<progresses.size();++i)
            {
                int days = (100 - progresses[i]) / speeds[i];
                if ((100 - progresses[i]) % speeds[i] != 0)
                    ++days;

                queue.push(days);
            }
            

            int day = 0;
            while (queue.empty() == false)
            {
                day = queue.front();
                int cnt = 0;
                while (queue.empty() == false && day >= queue.front())
                {
                    cnt++;
                    queue.pop();
                }
                answer.push_back(cnt);
            }


            return answer;
        }


        TEST_METHOD(TestMethod1)
        {
            auto result = solution({ 93, 30, 55 }, { 1, 30, 5 });
            Assert::AreEqual(2, result[0]);
            Assert::AreEqual(1, result[1]);
            //Assert::AreEqual({ 1, 3, 2 }, solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 }));


        }



    };
}
