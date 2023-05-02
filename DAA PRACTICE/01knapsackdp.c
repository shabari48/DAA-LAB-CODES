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
int knapsack(int weight, int wt[], int val[], int n)
{
    int i, w;
    int knap[n + 1][weight + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= weight; w++)
        {
            if (i == 0 || w == 0)
                knap[i][w] = 0;
            else if (wt[i - 1] <= w)
                knap[i][w] = max(val[i - 1] + knap[i - 1][w - wt[i - 1]], knap[i - 1][w]);
            else
                knap[i][w] = knap[i - 1][w];
        }
    }
    return knap[n][weight];
}

int main()
{
    int val[] = {0, 10, 12, 15, 20};
    int wt[] = {0, 1, 2, 2, 3};
    int weight = 5;
    int n = sizeof(val) / sizeof(val[0]);
    printf("The solution is : %d", knapsack(weight, wt, val, n));
    return 0;
}