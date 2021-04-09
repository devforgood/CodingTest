
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


    TEST_CLASS(Carpet)
    {
    public:

        vector<int> solution2(int brown, int yellow) {
            vector<int> answer;

            int v = brown + yellow;
            for (int i = 2; i < 5000; ++i)
            {
                for (int j = 2; j <= i; ++j)
                {
                    if (v == i * j 
                        && (i-2)*(j-2) == yellow // ���� �� ���� ����, �¿� ������ �����ϰ� ������ ���� ����
                        )
                    {
                        return answer = { i, j };
                    }
                }
            }
            return answer;
        }

        vector<int> solution(int brown, int red) {
            // ���ذ� �Ȱ�
            //w: ����, h: ����, w * h = brown + red, (w-2) * (h-2) = red, �� ���� red�� �����ؼ� �������������� Ǯ���
            //, w = brown/2 + 2 - h, h = n(��, n�� �ڿ���) �� �Ǵµ�, h���� ���Կ� ���� w���� �ڿ������� �ٲ� �׷���. h�� 1 �þ�ٴ� ���� w�� 1 �پ��� �Ͱ� ����
            int len = brown / 2 + 2;

            int w = len - 3;
            int h = 3;

            while (w >= h) {
                if (w * h == (brown + red)) break;

                w--;
                h++;
            }

            return vector<int>{w, h};
        }

        TEST_METHOD(TestMethod1)
        {
            auto result = solution(10, 2);
            Assert::AreEqual(4, result[0]);
            Assert::AreEqual(3, result[1]);

            result = solution(8, 1);
            Assert::AreEqual(3, result[0]);
            Assert::AreEqual(3, result[1]);

            result = solution(24, 24);
            Assert::AreEqual(8, result[0]);
            Assert::AreEqual(6, result[1]);

            result = solution(50, 22);
            Assert::AreEqual(24, result[0]);
            Assert::AreEqual(3, result[1]);

        }



    };
}
