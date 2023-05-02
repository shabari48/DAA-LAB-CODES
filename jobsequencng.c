#include<stdio.h>
void swap(float *x,float *y)
{
float temp;
temp=*x;
*x=*y;
*y=temp;
}
int main()
{
int i,j,m,n,max;
printf("Enter the number of objects:");
scanf("%d",&n);
float w[n],p[n],p_w[n],tot_w=0,tot_p=0;
float obj[n];
printf("Enter the maximum capacity:");
scanf("%d",&m);
for(i=1;i<=n;i++)
{
printf("\nEnter the weight of object %d:",i);
scanf("%f",&w[i]);
printf("Enter the profit of object %d:",i);
scanf("%f",&p[i]);
obj[i]=i;
p_w[i]=p[i]/(float)w[i]; 
}

for(i=1;i<=n;i++)
{
max=i;
for(j=i;j<=n-1;j++)
{
if(p_w[max]<p_w[j+1])
  max=j+1;
}
swap(&p_w[i],&p_w[max]);
swap(&w[i],&w[max]);
swap(&p[i],&p[max]);
swap(&obj[i],&obj[max]); 
}

float remind=m;
for(i=1;i<=n;i++)
{
if(remind>0)
{

if(w[i]<=remind)
{
tot_w=tot_w+w[i];
printf("\nObject %.0f is selected",obj[i]);
tot_p=tot_p+p[i];
remind=m-tot_w;
}
else
{
tot_p=tot_p+(p_w[i]*remind);
tot_w=tot_w+remind;
printf("\nObject %.0f is selected partially",obj[i]);
remind=m-tot_w;
}
}
}
printf("\nTotal profit %.2f",tot_p);
printf("\nTotal weight %.2f",tot_w);
return 0;
}
