#include <stdio.h>

int i, j, vertices, top = -1;

int visited[10];

int matrix[10][10], transpose[10][10];

int pre[10], post[10], parent[10];

int count = 0;

int stack[10];

int sccount = 0;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void dfs(int i)
{
    pre[i] = count;
    count++;
    printf("%d", i);
    visited[i] = 1;
    for (int j = 0; j < vertices; j++)
    {
        if (matrix[i][j] == 1 && visited[j] == 0)
        {
            parent[j] = i;
            dfs(j);
        }
    }
    post[i] = count;
    count++;
    push(i);
}

void trans()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }
}

void scc(int i)
{
    printf("%d->", i);
    visited[i] = 1;

    for (int j = 0; j < vertices; j++)
    {
        if (transpose[i][j] == 1 && visited[j] == 0)
            scc(j);
    }
}

void init()
{
    printf("Enter the no of vertices: ");
    scanf("%d", &vertices);

    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
        for (j = 0; j < vertices; j++)
        {
            printf("Enter the matrix connection  (%d,%d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void reinit()
{
    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }
}



int main()
{

    init();

    printf("\n\tDFS TRAVERSAL\n");

    for (i = 0; i < vertices; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }


    reinit();

    trans();


    printf("\n\nSTRONGLY CONNECTED COMPONENTS\n\n");

    while (top != -1)
    {
        int x = pop();
        if (visited[x] == 0)
        {

            scc(x);
            sccount++;
        }
        printf("\t");
    }

    printf("\n\nNo.of.strongly connected components: %d", sccount);
}
