#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef long long LL;

int exgcd(int a,int b,int* x,int* y)
{
	if (b == 0)
	{
		*x = 1, * y = 0;
		return a;
	}

	int gcd = exgcd(b, a % b, y, x);

	*x = *x;
	*y = (*y) - (a / b) * (*x);

	return gcd;
}
int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int a, b, m, x, y;
		scanf("%d%d%d", &a, &b, &m);

		int d = exgcd(a, m, &x, &y);

		if (b % d) puts("impossible");
		else printf("%d\n", (LL)b / d * x % m);
	}
	return 0;
}