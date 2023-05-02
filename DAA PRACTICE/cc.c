#include <stdio.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int coinchange(int d[], int n, int amount)
{
    int coin[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0 || j == 0)
            {
                coin[i][j] = 0;
            }
            else if (d[i-1] <= j)
                coin[i][j] = min(1 + coin[i][j - d[i - 1]], coin[i - 1][j]);
            else
                
        }
    }
    return coin[n][amount];
}

int main()
{
    int d[100];
    int n;
    int amount;
    printf("enter the amount to be changed");
    scanf("%d", &amount);
    printf("enter the no of coins");
    scanf("%d", &n);
    printf("enter the denomination set");
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
    }
    int u = coinchange(d, n, amount);
    printf("%d", u);
}