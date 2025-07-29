#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int n;

void divide(int x)
{
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			int s = 0;
			while (x % i == 0)
			{
				s++;
				x = x / i;
			}
			printf("%d %d\n", i, s);
		}
	}
	if (x > 1) printf("%d %d\n", x, 1);
	puts("");
}

int main(void)
{
	scanf("%d", &n);

	while (n--)
	{
		int x;
		scanf("%d", &x);
		
		divide(x);
	}
	return 0;
}