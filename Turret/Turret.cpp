
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h> 


int main(void) 
{ 
	int t, x1, y1, r1, x2, y2, r2, result; 
	double d;
	scanf("%d", &t); 
	while(t--) 
	{ 
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2); 
		d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (r1 + r2 < d)
			result = 0;
		else if (abs(r1 - r2) > d)
			result = 0;
		else if (d == 0 && r1 == r2)
			result = -1;
		else if (d == (r1 + r2))
			result = 1;
		else if (d == abs(r1 - r2))
			result = 1;
		else
			result = 2;

		printf("%d\n", result); 
	} 
}

