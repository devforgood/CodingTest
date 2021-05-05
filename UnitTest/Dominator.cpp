
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
    TEST_CLASS(Dominator)
    {
    public:


        int solution(vector<int>& A) {
            map<int, int> map;
            int max = 0;
            int max_value = 0;
            for (int i = 0; i < A.size(); ++i)
            {
                map[A[i]] += 1;
                if (max < map[A[i]])
                {
                    max = map[A[i]];
                    max_value = A[i];
                }
            }

            if (max > A.size() / 2)
            {
                for (int i = 0; i < A.size(); ++i)
                {
                    if (A[i] == max_value)
                        return i;
                }
            }
            return -1;
        }


        TEST_METHOD(TestMethod1)
        {

            Assert::AreEqual(0, solution(vector<int>({ 3,4,3,2,3,-1,3,3 })));
        }
    };
}
