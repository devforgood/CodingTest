
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


    TEST_CLASS(Joystick)
    {
    public:
        int solution2(string name) {
            int answer = 0;
            char start = 'A';
            char end = 'Z';

            int distance = 0;
            for (int i = 0; i < name.size();)
            {
                if (name[i] == start)
                {
                    int index = 0;
                    distance = 0;
                    for (int j = i; j < name.size(); ++j)
                    {
                        if (name[j] != start)
                        {
                            index = j;
                            break;
                        }
                        ++distance;
                    }

                    distance = min(((int)name.size() - index + i -2), distance);
                    i = index;
                    answer += distance;
                }
                else
                {

                    distance = name[i] - start;
                    distance = min((end - name[i] + 1), distance);

                    ++i;
                    answer += distance;

                    if (i == name.size())
                        break;

                    answer += 1;
                }
            }


            return answer;
        }

        int solution2(string name)
        {
            int answer = 0;
            char start = 'A';
            char end = 'Z';
            int distance = 0;

            vector<int> diff;
            for (int i = 0; i < name.size(); ++i)
            {
                if (name[i] != start)
                    diff.push_back(i);
                else if(i==0)
                    diff.push_back(0);
            }

            int cursor = 0;
            int next_cursor = 0;
            int left = 1;
            int right = diff.size() - 1;
            for (int i = 0; i < diff.size(); ++i)
            {
                if (i + 1 != diff.size())
                {
                    if (cursor > diff[right])
                    {
                        if (cursor - diff[right] <= name.size()  - cursor + diff[left])
                        {
                            answer += cursor - diff[right];
                            next_cursor = diff[right];
                            --right;
                        }
                        else
                        {
                            answer += name.size() - cursor + diff[left];
                            next_cursor = diff[left];
                            ++left;
                        }

                    }
                    else
                    {
                        if (diff[left] - cursor <= name.size() - diff[right] + cursor)
                        {
                            answer += diff[left] - cursor;
                            next_cursor = diff[left];
                            ++left;
                        }
                        else
                        {
                            answer += name.size() - diff[right] + cursor;
                            next_cursor = diff[right];
                            --right;
                        }
                    }
                }

                distance = name[cursor] - start;
                distance = std::min((end - name[cursor] + 1), distance);
                answer += distance;
                cursor = next_cursor;
            }




            return answer;
        }


        //���̽�ƽ�� �����ϼ��ִ� �ּҰ�ο� ���ؼ���, 
        // (i) �������� i��°�� ���� ���ٰ�, �������� ���ư��� �������Ͽ� next_i��°�� �����Ѵ�. 
        // (ii) �������� �������ؼ� next_i��°�� ���� ���ٰ�, �������� �������ؼ� ���ư��� i��°�� �����Ѵ�, 
        // ���� �ϳ��̴�. for������ ������ i���� �׿� �����ϴ� next_i��°�� ���� ���� Ž���Ҷ�����,
        //  ������ �������� �����ؼ� ���� 2���� ��� �� �ּҰ�θ� Ž���ϴ� ����(��ü���� min�� ã�� ����)�� �ϰԵ�.
        // ���� left_right���� ����� i���� �װ��� next_i�� �̵��Ҷ� �ּҰ���� (i)�Ǵ� (ii)�� �ϳ��� ����� ����.
        // (��, i�Ǵ� ii�� ����� ����. �ּҰ�δϱ� i�ߴٰ� ii�ߴٰ� i�ߴٰ� ii�ߴٰ� i�ϴ� ��������� �ȳ���). 
        // ���� ��, [A 2��]C[A 100��]C[A 1�ﰳ]C[A 2��] ��� �����غ���, �������ؼ� C����ٰ� �������� ���ư���, [A1�ﰳ] �տ��ִ� C���� �������� ��ΰ� ���� ������ ���� left_right�� ����.
        int solution(string name) {
            int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

            int answer = 0;
            for (auto ch : name)
                answer += LUT[ch - 'A'];
            int len = name.length();
            int left_right = len - 1;
            for (int i = 0; i < len; ++i) {
                int next_i = i + 1;
                while (next_i < len && name[next_i] == 'A')
                    next_i++;
                left_right = min(left_right, i + len - next_i + min(i, len - next_i));
            }
            answer += left_right;
            return answer;
        }
        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(11, solution("JAZ"));
			Assert::AreEqual(11, solution("ABABAAAAABA"));

			Assert::AreEqual(56, solution("JEROEN"));


			Assert::AreEqual(23, solution("JAN"));


        }



    };
}
