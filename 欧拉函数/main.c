#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int phi(int n)
{
	int res = n;
	for (int i = 2; i <= n / i; i++)
	{
		if (n % i == 0)
		{
			res = res / i * (i - 1);
			while (n % i == 0) n = n / i;
		}
	}

	if (n > 1) res = res / n * (n - 1);
	return res;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int x;
		scanf("%d", &x);

		printf("%d\n", phi(x));
	}
	return 0;
}