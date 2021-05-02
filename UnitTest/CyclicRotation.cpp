
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
    TEST_CLASS(CyclicRotation)
    {
    public:
        vector<int> solution(vector<int>& A, int K) {
            
            if (A.empty())
                return A;
            for (int i = 0; i < K; ++i)
            {
                int a = *A.rbegin();
                A.pop_back();
                A.insert(A.begin(), a);
            }
            return A;
        }




        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(true, solution(vector<int>({ 3, 8, 9, 7, 6 }), 3) == vector<int>({9, 7, 6, 3, 8}));
        }
    };
}
