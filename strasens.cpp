#include<stdio.h>
#include<math.h>
int a[10][10],b[10][10],C[10][10];
int n,t;
int p1,p2,p3,p4,p5,p6,p7,c1,c2,c3,c4,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
void strassen(int m,int ar,int ac,int br,int bc,int cr,int cc)
{
 if(m==2)
 {
 s1=b[br][bc+1]-b[br+1][bc+1];
 s2=a[ar][ac]+a[ar][ac+1];
 s3=a[ar+1][ac]+a[ar+1][ac+1];
 s4=b[br+1][bc]-b[br][bc];
 s5=a[ar][ac]+a[ar+1][ac+1];
 s6=b[br][bc]+b[br+1][bc+1];
 s7=a[ar][ac+1]-a[ar+1][ac+1];
 s8=b[br+1][bc]+b[br+1][bc+1];
 s9=a[ar][ac]-a[ar+1][ac];
 s10=b[br][bc]+b[br][bc+1];
 
 p1=a[ar][ac]*s1;
 p2=s2*b[br+1][bc+1];
 p3=s3*b[br][bc];
 p4=a[ar+1][ac+1]*s4;
 p5=s5*s6;
 p6=s7*s8;
 p7=s9*s10;
 
 C[cr][cc]+=p5+p4-p2+p6;
 C[cr][cc+1]+=p1+p2;
 C[cr+1][cc]+=p3+p4;
 C[cr+1][cc+1]+=p5+p1-p3-p7;
 }
 else
 {
 m=m/2;
 strassen(m,ar,ac,br,bc,ar,ac);
 strassen(m,ar,ac+m,br+m,bc,ar,ac);
 strassen(m,ar,ac,br,bc+m,ar,ac+m);
 strassen(m,ar,ac+m,br+m,bc+m,ar,ac+m);
 strassen(m,ar+m,ac,br,bc,ar+m,ac);
 strassen(m,ar+m,ac+m,br+m,bc,ar+m,ac);
 strassen(m,ar+m,ac,br,bc+m,ar+m,ac+m);
 strassen(m,ar+m,ac+m,br+m,bc+m,ar+m,ac+m);
 }
}
void main()
{
 printf("\nEnter the n:");
 scanf("%d",&n);
 int i=1;
 while(1)
 {
 	
 t=pow(2,i++);
 if(t>=n)
 {
 break;
 }
 }
 
 for(int i=0;i<t;i++)
 {
 for(int j=0;j<t;j++)
 {
 C[i][j]=b[i][j]=a[i][j]=0;
 }
 } 
 
 printf("\nMATRIX 1:\n");
 for(int i=0;i<n;i++)
 {
 for(int j=0;j<n;j++)
 {
 scanf("%d",&a[i][j]);
 }
 }
 printf("\nMATRIX 2:\n");
 for(int i=0;i<n;i++)
 {
 for(int j=0;j<n;j++)
 {
 scanf("%d",&b[i][j]);
 }
 } 
 strassen(t,0,0,0,0,0,0);
 printf("PRODUCT OF MATRIX 1 and 2:\n");
 for(int i=0;i<n;i++)
 {
 for(int j=0;j<n;j++)
 {
 printf("%d\t",C[i][j]);
 }
 printf("\n");
 } 
