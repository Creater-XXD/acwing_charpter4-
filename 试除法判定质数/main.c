#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int n;

bool is_prime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= n / i; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main(void)
{
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);

		if (is_prime(x)) puts("Yes");
		else puts("No");
	}
	return 0;
}