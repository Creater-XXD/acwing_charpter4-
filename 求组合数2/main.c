#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef long long LL;
#define N 100010
#define MOD 1000000007

int fact[N], infact[N];

int qmi(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 0x1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b = b >> 1;
	}
	return res;
}

int main(void)
{
	fact[0] = infact[0] = 1;

	for (int i = 1; i < N; i++)
	{
		fact[i] = (LL)fact[i - 1] * i % MOD;
		infact[i] = (LL)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
	}

	int n;
	scanf("%d", &n);

	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		printf("%d\n", (LL)fact[a] * infact[b] % MOD * infact[a - b] % MOD);
	}
	return 0;
}