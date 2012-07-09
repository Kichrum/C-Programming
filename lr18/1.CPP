#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void vvod(double *a,int n)
{

 for(int i=0;i<n;i++)
{  printf("%d=",i+1); scanf("%lf",&a[i]);}
}

double maxln(double *a,int n)
{
 double max;
 max=a[0];
 for(int i=1;i<n;i++)
  if(a[i]>max) max=a[i];
 if(max>=0) return log(max);
 else {printf("ERROR!");
 getch();}
}

void main()
{
 clrscr();
 double *a;
 int n;
  printf("N="); scanf("%d",&n);
 a=(double*)malloc(n*sizeof(double));
 vvod(a,n);
 printf("\nVidpovid': %lf",maxln(a,n));

 free(a);
 getch();
}