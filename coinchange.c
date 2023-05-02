#include<stdio.h>
int d[100];
int soln[100];
int n;
void coinchange(int cost)
{
int j=0;
for(int i=0;i<n;i++)
{
while(cost>=d[i])
{

cost=cost-d[i];
soln[j]=d[i];
j++;
}
}
if(j==0||cost!=0)
printf("No solution");
else
{
       printf("The changed amount are");
  for(int i=0;i<j;i++)
  {
printf("\n%d\t",soln[i]);
  }
   }
}
int main()
{
int amount,temp;
printf("Enter the no of coins");
scanf("%d",&n);
printf("Enter the coins in denomination the set");
for(int i=0;i<n;i++)
{
scanf("%d",&d[i]);
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(d[j]<d[j+1])
{
     temp=d[j];
 d[j]=d[j+1];
 d[j+1]=temp;
}
}
}
printf("The denomiation set are");
for(int i=0;i<n;i++)
{
printf("%d\t",d[i]);
}
printf("\nEnter the amount to be changed");
scanf("%d",&amount);
coinchange(amount);
}