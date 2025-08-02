#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int gcd(int a, int b)
//{
//	while (b != 0)
//	{
//		int t = a % b;
//		a = b;
//		b = t;
//	}
//
//	return a;
//}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		printf("%d\n", gcd(a, b));
	}

	return 0;
}