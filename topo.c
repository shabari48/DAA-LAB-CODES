#include<stdio.h>
#include<stdlib.h>
int n,s,stack[50],a[50][50],v[50],p[20],top=-1,pre[40],post[40];
int count=0;
void push(int x)
{
   stack[++top]=x;
}
void dfs(int s)
  {
    pre[s]=count;
    count++;
    int t;
    for(t=1;t<=n;t++)
     {
        if(a[s][t]==1 && v[t]==0)
          {
            push(t);
            v[t]=1;
            p[t]=s;
            dfs(t);
          }
     }
    post[s]=count;
    printf("%d\n",s);
    count++;
    
  }
int main()
  {
    int i,j,k;
    printf("Enter the no of vetices:");
    scanf("%d",&n);
    printf("Enter the matrix representation");
    for(i=1;i<=n;i++)
     {
       for( j=1;j<=n;j++)
        {
           printf("(%d,%d)",i,j);
           scanf("%d",&a[i][j]);
         }
       v[i]=0;
       p[i]=-1;
     }
    printf("Enter the source vertex:");
    scanf("%d",&s);
    push(s);
    v[s]=1;
    printf("topological sort:\n");
    dfs(s);
    for(i=1;i<=n;i++)
    {
        if(v[i]==0)
          {
              dfs(i);
          }
    }
    printf("\nVertices\tParent\tPre\tPost\n");
    for(i=1;i<=n;i++)
        printf("%d\t\t%d\t\t%d\t%d\n",i,p[i],pre[i],post[i]);
        
    return 0;
  }
