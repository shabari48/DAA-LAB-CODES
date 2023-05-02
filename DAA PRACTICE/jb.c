#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int knapsack(int ob, int w[], int p[], int m)
{

    int knap[ob + 1][m + 1];
    for (int i = 0; i <= ob; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (w[i - 1] <= j)
                knap[i][j] = max(knap[i - 1][j], p[i - 1] + knap[i - 1][j - w[i - 1]]);
            else
                knap[i][j] = knap[i - 1][j];
        }
    }
    return knap[ob][m];
}
int main()
{
    int ob, w[100], p[100];
    printf("enter the no of ob");
    scanf("%d", &ob);
    printf("enter the weight array");
    for (int i = 0; i < ob; i++)
        scanf("%d", &w[i]);
    printf("enter the profit array");
    for (int i = 0; i < ob; i++)
        scanf("%d", &p[i]);
    int m;
    printf("enter the max weight");
    scanf("%d", &m);
    int u = knapsack(ob, w, p, m);
    printf("%d", u);
}