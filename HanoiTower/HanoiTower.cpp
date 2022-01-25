#include <iostream>
#include <math.h>

using namespace std;

void move(int from, int to)
{
	cout << from << " " << to << '\n';
}
// hanoi(x, y, z)
// x, z, y
// x, y
// z, y, x

void hanoi(int n, int from, int by, int to)
{
	if (n == 0) return;
	hanoi(n - 1, from, to, by);
	move(from, to);
	hanoi(n - 1, by, from, to);
}

int main()
{
	int n;
	cin >> n;

	cout << (int)pow(2, n)-1 << '\n';
	hanoi(n, 1, 2, 3);

}

