#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define N 2000

int res[N];

void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;

	int i = l - 1, j = r + 1;
	int x = q[l + r >> 1];

	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);

		if (i < j)
		{
			int tmp = q[i];
			q[i] = q[j];
			q[j] = tmp;
		}
	}

	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

void get_divisor(int n)
{
	memset(res, -1, sizeof res);
	int cnt = 0;
	
	for (int i = 1; i <= n / i; i++)
	{
		if (n % i == 0)
		{
			res[cnt++] = i;
			if (i != n / i) res[cnt++] = n / i;
		}
	}

	quick_sort(res, 0, cnt - 1);

	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", res[i]);
	}
	puts("");
}

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int x;
		scanf("%d", &x);

		get_divisor(x);
	}
	return 0;
}