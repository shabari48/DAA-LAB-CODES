#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long noofdigits(long u, long v)
{
    long b = 0;
    long max;
    if (u >= v)
        max = u;
    else
        max = v;
    while (max > 0)
    {
        max = max / 10;
        b++;
    }

    return b;
}

long prod(long u, long v)
{
    long n = noofdigits(u, v);
    long w, x, y, z, p, q, r, m;
    if (u == 0 || v == 0)
        return 0;
    else if (n <= 2)
        return u * v;
    else
    {
        m = floor(n / 2);
        w = u / pow(10, m);
        x = u % (int)pow(10, m);
        y = v / pow(10, m);
        z = v % (int)pow(10, m);
        p = prod(w, y);
        q = prod(x, z);
        r = prod(w + x, y + z);
        return p * pow(10, 2 * m) + (r - p - q) * pow(10, m) + q;
    }
}

int main()
{
    long m1, m2;
    printf("Enter the number 1: ");
    scanf("%ld", &m1);
    printf("Enter the number 2: ");
    scanf("%ld", &m2);
    long result = prod(m1, m2);
    printf("The result is %ld\n", result);
}