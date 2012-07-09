#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 void vvod(double**,int&);
 int kilk(double**,int,int);
 void clear(double**,int);
void main()
{
 clrscr();
 double **a,q;
 int m,n,i,j;
 scanf("%lf",&q);
 vvod(a,n);
 if (n==NULL) {puts("ERROR!"); getch();}
 for(i=0;i<n;i++)
  printf("\nV ryadku %d: %d",i+1,kilk(a,n,i));
 clear(a,n);
 getch();
}
void vvod(double **a,int &n)
{
 int i,j;
 printf("N="); scanf("%d",&n);
 a=(double**)calloc(n,sizeof(double*));
//  if(!a) {puts("ERROR!"); getch();}
 for(i=0;i<n;i++)
  {
   a[i]=(double*)calloc(n,sizeof(double));
//    if(!a[i]) {puts("ERROR!"); getch();}
   for(j=0;j<n;j++)
    {
     printf("a(%d;%d)=",i+1,j+1); scanf("%lf",&a[i][j]);
     printf("%lf",a[i][j]);
    }
  }
}
int kilk(double **a,int n,int i)
{
 int j,k=0;
 for(j=0;j<n;j++)
   if(a[i][j]>0) k++;
 return k;
}
void clear(double **a,int n)
{
 int i;
 for(i=0;i<n;i++)
   free(a[i]);
 free(a);
}