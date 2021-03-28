
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

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(GymClothes)
    {
    public:


        int solution(int n, vector<int> lost, vector<int> reserve) {

            sort(lost.begin(), lost.end());
            set<int> reserve_set(reserve.begin(), reserve.end());

            n -= lost.size();
            for (vector<int>::iterator itr = lost.begin(); itr != lost.end();)
            {
                set<int>::iterator itr2;
                itr2 = reserve_set.find((*itr));
                if (itr2 != reserve_set.end())
                {
                    ++n;
                    reserve_set.erase(itr2);
                    itr = lost.erase(itr);
                }
                else
                {
                    ++itr;
                }
            }
            for (vector<int>::iterator itr = lost.begin(); itr != lost.end(); ++itr)
            {
                set<int>::iterator itr2;
                itr2 = reserve_set.find((*itr) - 1);
                if (itr2 != reserve_set.end())
                {
                    ++n;
                    reserve_set.erase(itr2);
                    continue;
                }
                itr2 = reserve_set.find((*itr) + 1);
                if (itr2 != reserve_set.end())
                {
                    ++n;
                    reserve_set.erase(itr2);
                }

            }


            return n;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> lost = { 2, 4 };
            vector<int> reserve = { 1, 3, 5 };

            Assert::AreEqual(5, solution(5, lost, reserve));
        }
        TEST_METHOD(TestMethod2)
        {
            vector<int> lost = { 3 };
            vector<int> reserve = { 1 };

            Assert::AreEqual(2, solution(3, lost, reserve));
        }


    };
}
