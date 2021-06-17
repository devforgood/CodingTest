//#include <iostream>
//using namespace std;
//void star(int i, int j, int num)
//{
//    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
//        cout << ' ';
//    }
//    else
//    {
//        if (num / 3 == 0)
//            cout << '*';
//        else
//            star(i, j, num / 3);
//    }
//}
//int main() {
//    int num;
//    cin >> num;
//    for (int i = 0; i < num; i++)
//    {
//        for (int j = 0; j < num; j++)
//            star(i, j, num);
//        cout << '\n';
//    }
//}


#include <iostream>
using namespace std;

char map[3000][3000];

void init() {
	for (int i = 0; i < 3000; ++i) {
		for (int j = 0; j < 3000; ++j) {
			map[i][j] = ' ';
		}
	}
}

void solve(int n, int x, int y) {
	if (n == 1) {
		map[x][y] = '*';
		return;
	}
	int div = n / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) {
				continue;
			}
			solve(div, x + (div * i), y + (div * j));
		}
	}
	return;
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;

	init();
	solve(n, 0, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}