#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef long long LL;

int qmi(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 0x1) res = (LL)res * a % p;
		a = (LL)a * a % p;
		b = b >> 1;
	}
	return res;
}

int C(int a, int b, int p)
{
	if (b > a) return 0;
	
	LL x = 1, y = 1;

	for (int i = 0; i < b; i++)
	{
		x = x * (a - i) % p;
		y = y * (i + 1) % p;
	}

	return x * qmi(y, p - 2, p) % p;
}

int lucas(LL a, LL b, int p)
{
	if (a < p && b < p) return C(a, b, p);
	else return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		LL a, b;
		int p;

		scanf("%lld%lld%d", &a, &b, &p);

		printf("%d\n", lucas(a, b, p));
	}
	return 0;
}