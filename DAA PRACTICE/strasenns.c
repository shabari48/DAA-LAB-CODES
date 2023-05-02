#include <stdio.h>
#include <stdlib.h>
int a[20][20], b[20][20], c[20][20];

int ar = 0, ac = 0, br = 0, bc = 0, cr = 0, cc = 0;

void strasenns(int m, int ar, int ac, int br, int bc, int cr, int cc)
{
    if (m == 2)
    {

        int s1 = b[br][bc + 1] - b[br + 1][bc + 1]; // f-h
        int s2 = a[ar][ac] + a[ar][ac + 1];         // a+b
        int s3 = a[ar + 1][ac] + a[ar + 1][ac + 1]; // c+d
        int s4 = b[br + 1][bc] - b[br][bc];         // g-e
        int s5 = a[ar][ac] + a[ar + 1][ac + 1];     // a+d
        int s6 = b[br][bc] + b[br + 1][bc + 1];     // e+h
        int s7 = a[ar][ac + 1] - a[ar + 1][ac + 1]; // b-d
        int s8 = b[br + 1][bc] + b[br + 1][bc + 1]; // g+h
        int s9 = a[ar][ac] - a[ar + 1][ac];         // a-c
        int s10 = b[br][bc] + b[br][bc + 1];        // e+f

        int p1 = a[ar][ac] * s1;         // a*(f-h)
        int p2 = b[br + 1][bc + 1] * s2; // h*(a+b)
        int p3 = b[br][bc] * s3;         // e*(c+d)
        int p4 = a[ar + 1][ac + 1] * s4; // d*(g-e)
        int p5 = s5 * s6;                //(a+d)(e+h)
        int p6 = s7 * s8;                //(b-d)(g+h)
        int p7 = s9 * s10;               //(a-c)(e+f)

        int r = p6 + p5 + p4 - p2;
        int s = p1 + p2;
        int t = p3 + p4;
        int u = p1 + p5 - p3 - p7;

        c[cr][cc] += r;
        c[cr][cc + 1] += s;
        c[cr + 1][cc] += t;
        c[cr + 1][cc + 1] += u;
    }
    else
    {
        m = m / 2;
        strasenns(m, ar, ac, br, bc, ar, ac);
        strasenns(m, ar, ac + m, br + m, bc, ar, ac);
        strasenns(m, ar, ac, br, bc + m, ar, ac + m);
        strasenns(m, ar, ac + m, br + m, bc + m, ar, ac + m);
        strasenns(m, ar + m, ac, br, bc, ar + m, ac);
        strasenns(m, ar + m, ac + m, br + m, bc, ar + m, ac);
        strasenns(m, ar + m, ac, br, bc + m, ar + m, ac + m);
        strasenns(m, ar + m, ac + m, br + m, bc + m, ar + m, ac + m);
    }
}

int main()
{
    int n, t;

    printf("Enter the number of dimensions: ");
    scanf("%d", &n);
    t = n;

    printf("enter the matrix 1\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("enter the matrix 2\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
            c[i][j] = 0;
        }
    }

    strasenns(t, 0, 0, 0, 0, 0, 0);

    printf("\nTHE PRODUCT MATRIX\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}