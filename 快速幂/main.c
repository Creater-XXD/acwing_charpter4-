#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef long long LL;

int qmi(int a, int b, int p)
{
	int res = 1 % p;

	while (b)
	{
		if (b & 0x1) res = (LL)res * a % p;

		b = b >> 1;
		a = (LL)a * a % p;
	}
	
	return res;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int a, b, p;
		scanf("%d%d%d", &a, &b, &p);

		printf("%d\n", qmi(a, b, p));
	}
	return 0;
}