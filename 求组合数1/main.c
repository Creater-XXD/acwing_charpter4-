#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 2010
#define MOD 1000000007

int c[N][N];

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	
	init();

	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		printf("%d\n", c[a][b]);
	}
	return 0;
}