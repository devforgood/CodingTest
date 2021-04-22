
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


    TEST_CLASS(MockTest)
    {
    public:


        vector<int> solution(vector<int> answers) {
            vector<int> answer;
            vector<int> u1 = { 1, 2, 3, 4, 5 };
            vector<int> u2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
            vector<int> u3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

            vector<int> cnt(3, 0);
            for (int i = 0; i < answers.size(); ++i)
            {
                if (answers[i] == u1[i % u1.size()])
                    ++cnt[0];
                if (answers[i] == u2[i % u2.size()])
                    ++cnt[1];                
                if (answers[i] == u3[i % u3.size()])
                    ++cnt[2];
            }

            int max_value = *max_element(cnt.begin(), cnt.end());
            for (int i = 0; i < cnt.size(); ++i)
            {
                if (cnt[i] == max_value)
                    answer.push_back(i + 1);
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            auto r = solution({ 1,2,3,4,5 });
            Assert::AreEqual(1, r[0]);

            auto r2 = solution({ 1,3,2,4,2 });
            Assert::AreEqual(1, r2[0]);
            Assert::AreEqual(2, r2[1]);
            Assert::AreEqual(3, r2[2]);



        }



    };
}
