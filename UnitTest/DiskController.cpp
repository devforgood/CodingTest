
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
    bool compare(vector<int> a, vector<int> b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    }

    TEST_CLASS(DiskController)
    {
    public:
        int solution2(vector<vector<int>> jobs) {
            int answer = 0;

            sort(jobs.begin(), jobs.end(), compare);
            
            int sum = 0;
            for (int i = 0; i < jobs.size(); ++i)
            {
                answer += jobs[i][1] + sum - jobs[i][0];
                sum += jobs[i][1];
            }

            answer /= jobs.size();

            return answer;
        }

        struct cmp {
            bool operator()(vector<int> a, vector<int> b) {
                return a.at(1) > b.at(1);
            }
        };

        int solution(vector<vector<int>> jobs) {
            //��� ����� ����, �ε��� ������, �ð�üũ��
            int answer = 0, j = 0, time = 0;
            //�ð��� ���� ������������ ����
            sort(jobs.begin(), jobs.end());
            priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //�켱���� ť min heap
            //��⿭�� ���� �켱���� ť�� �������� �ݺ�
            while (j < jobs.size() || !pq.empty()) {
                //���� ��⿭�� �����ְ�, ���� ��⿭�� ����ð����� �۴ٸ�
                if (jobs.size() > j && time >= jobs[j][0]) {
                    //�켱���� ť�� �߰�
                    pq.push(jobs[j++]);
                    //�ε��� ����
                    //�����ð��뿡 �ٸ��۾��� �������� �� �����Ƿ� �ٽ� Ȯ��
                    continue;
                }
                //ť�� ������� �ʴٸ�
                if (!pq.empty()) {
                    //�ð��� ���۾��� ���������� �ɸ��� �ð���ŭ �߰�
                    time += pq.top()[1];
                    //�۾��ð��� ��� �ð���ŭ �߰�(����ð� - ���� �ð�)
                    answer += time - pq.top()[0];
                    //�۾��� �������Ƿ� �켱���� ť���� ����
                    pq.pop();
                }
                else //ť�� ����ִٸ� �����۾� �ð����� �ѱ�
                    time = jobs[j][0];
            }
            return answer / jobs.size();//����� ���ؾ��ϹǷ� ���۾��� ������ ������
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> jobs = {{1, 3}, {3, 9}, {2, 6}};

            Assert::AreEqual(9, solution(jobs));

        }



    };
}
