#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

#define N 1000010

int primes[N], cnt;
bool st[N];

void get_prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!st[i]) primes[cnt++] = i;

		for (int j = 0; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	get_prime(n);

	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", primes[i]);
	}

	return 0;
}