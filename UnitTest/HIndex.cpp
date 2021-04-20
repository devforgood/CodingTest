
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


    TEST_CLASS(HIndex)
    {
    public:


        int solution(vector<int> citations) {

            sort(citations.begin(), citations.end(), greater<int>());
            int i;
            for (i = 0; i < citations.size(); ++i)
            {
                if (citations[i] < i+1)
                    return i;
            }

            return i;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution({ 10,11,12,13 }));
            Assert::AreEqual(3, solution({ 3, 0, 6, 1, 5 }));

        }



    };
}
