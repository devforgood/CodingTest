#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(NExpression)
    {
    public:

        int get_basic_number(int N, int cnt) {
            int res = 0;

            while (cnt > 0) {
                cnt -= 1;
                res += N * pow(10, cnt);
            }

            return res;
        }

        int solution(int N, int number) {
            // ��n���� ���� �ǵ�� -> �׽�Ʈ ���̽��� �ٲ�鼭 ���� ������ �߰��ؾ� ��.
            if (N == number) {
                return 1;
            }

            int answer = -1;

            const int MIN = 8;
            //1. [ {} x 8 ] �ʱ�ȭ
            auto s = vector<set<int>>(MIN);
            // 2. �� set���� �⺻ �� "N" * i �� �ʱ�ȭ
            int idx = 1;

            for (auto& x : s) {
                x.insert(get_basic_number(N, idx));
                idx += 1;
            }

            //3. n �Ϲ�ȭ
            //   { 
            //       "n" * i, 
            //       1�� set ��Ģ���� n-1�� set, 
            //       2�� set ��Ģ���� n-2�� set, 
            //       ...
            //       n-1�� set ��Ģ���� 1�� set, 
            //    } 
            // number�� ���� �ּҷ� ����� �� ����.
            for (int i = 1; i < MIN; i++) {
                for (int j = 0; j < i; j++) {
                    for (const auto& op1 : s[j]) {
                        for (const auto& op2 : s[i - j - 1]) {
                            s[i].insert(op1 + op2);
                            s[i].insert(op1 - op2);
                            s[i].insert(op1 * op2);

                            if (op2 != 0)
                                s[i].insert(op1 / op2);
                        }
                    }
                }

                if (s[i].find(number) != s[i].end()) {
                    answer = i + 1;
                    break;
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution(5, 12));
        }


    };
}
