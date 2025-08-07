#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int exgcd(int a, int b, int* x, int* y)
{
	if (b == 0)
	{
		*x = 1, * y = 0;
		return a;
	}

	int t = exgcd(b, a % b, y, x);
	*x = *x;
	*y = (*y) - (a / b) * (*x);

	return t;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int a, b, x, y;
		scanf("%d%d", &a, &b);

		exgcd(a, b, &x, &y);

		printf("%d %d\n", x, y);
	}
	return 0;
}