#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

int n, cnt = 0;
int board[16] = { 0, };

bool check(int col)
{
    for (int i = 0; i < col; ++i)
    {
        if (board[col] == board[i] || col - i == abs(board[col] - board[i]))
            return false;
    }
    return true;
}

void nqueen(int col)
{
    if (col == n)
    {
        ++cnt;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        board[col] = i;
        if (check(col))
        {
            nqueen(col + 1);
        }

    }


}

int main(void) 
{
    scanf("%d", &n);

    nqueen(0);

    printf("%d\n", cnt);

    return 0;
}


