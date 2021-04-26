
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

    int map[101][101];
    int dest_x;
    int dest_y;

    TEST_CLASS(WayToSchool)
    {
    public:

        int DFS(int x, int y)
        {
            if (x == dest_x && y == dest_y)
                return 1;

            if (x > dest_x || y > dest_y)
                return 0;

            if (map[x][y] != -1)
                return map[x][y];

            int cnt = DFS(x + 1, y);
            cnt += DFS(x, y + 1);
            map[x][y] = cnt;
            return cnt;
        }

        int solution2(int m, int n, vector<vector<int>> puddles) {
            dest_x = m;
            dest_y = n;

            for (int i = 0; i <= m; ++i)
                for (int j = 0; j <= n; ++j)
                    map[i][j] = -1;

            for (auto p : puddles)
            {
                map[p[0]][p[1]] = 0;
            }

            for (int x = m; x > 0; --x)
            {
                for (int y = n; y > 0; --y)
                {
                    DFS(x, y);
                }
            }


            return map[1][1];
        }

        int solution3(int m, int n, vector<vector<int>> puddles) {


            for (int i = 0; i <= m; ++i)
                for (int j = 0; j <= n; ++j)
                    map[i][j] = 1;

            for (auto p : puddles)
            {
                int x = p[0];
                int y = p[1];
                map[x][y] = 0;

                if (x == 1) {
                    for (int j = y; j <= n; j++)
                        map[1][j] = 0;
                }

                if (y == 1) {
                    for (int j = x; j <= m; j++)
                        map[j][1] = 0;
                }
            }

            for (int x = m; x > 0; --x)
            {
                for (int y = n; y > 0; --y)
                {
                    if (x == m && y == n)
                        continue;

                    if (map[x][y] == 0)
                        continue;


                    map[x][y] = ((long)(map[x + 1][y] + map[x][y + 1])) % 1000000007;
                }
            }


            return map[1][1];
        }
        int solution(int m, int n, vector<vector<int>> puddles) {
            vector<vector<int>> board(n + 1, vector<int>(m + 1, 1));

            for (int i = 0; i < puddles.size(); i++) {
                int y = puddles[i][1];
                int x = puddles[i][0];

                // 잠긴 지역 0으로 표시
                board[y][x] = 0;

                if (x == 1) {
                    for (int j = y; j <= n; j++)
                        board[j][1] = 0;
                }

                if (y == 1) {
                    for (int j = x; j <= m; j++)
                        board[1][j] = 0;
                }
            }


            for (int y = 2; y <= n; y++) {
                for (int x = 2; x <= m; x++) {
                    if (board[y][x] == 0)
                        continue;

                    board[y][x] = (board[y - 1][x] + board[y][x - 1]) % 1000000007;
                }
            }

            return board[n][m];
        }
        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution(4, 3, { {2, 2} }));



        }



    };
}
