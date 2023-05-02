#include <stdio.h>
int m[11][11], s[11][11];
void pr(int s[11][11], int i, int j)
{
    if (i == j)
    {
        printf("a%d", i);
    }
    else
    {
        printf("(");
        pr(s, i, s[i][j]);
        pr(s, s[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    int n, p[11];
    printf("enter  the no of matrix");
    scanf("%d", &n);
    printf("enter the size");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    int min, q, j;
    for (int d = 1; d <= n - 1; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            j = i + d;
            min = 99999;
            for (int k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[j] * p[k];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    printf("\n the output matrix is\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\n the output matrix is\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("the optimal is %d\n", m[1][n]);
    pr(s, 1, n);
}