#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void vvod(float**a,int n)
{
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
   {printf("\na(%d;%d)=",i,j); scanf("%f",&a[i][j]);}
}
int pol(float **a,int n, int i)
{
 int kol=0;
 for(int j=0;j<n;j++)
  if(a[i][j]>0) kol++;
 return kol;
}
void main(void)
{
 clrscr();
 float **a,q;
 int n,i,k;

 //scanf("%lf",&q);
 printf("N="); scanf("%d",&n);
 a=(float**)calloc(n,sizeof(float*));
 for(i=0;i<n;i++)
  a[i]=(float*) calloc(n,sizeof(float));
 vvod(a,n);
 for(i=0;i<n;i++)
  printf("\nDodatnih v ryadku %d: %d",i,pol(a,n,i));
 for(i=0;i<n;i++)
  free(a[i]);
 free(a);
 getch();
}