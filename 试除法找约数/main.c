#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 2000

int res[N];

int cmp_int(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
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

    qsort(res, cnt, sizeof(int), cmp_int);

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