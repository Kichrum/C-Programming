#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct pol
{
 int x3;
 int x2;
 int x1;
 int x0;
}pol;

void vvod(pol*a)
{
 printf("Nehay polinom ax3+bx2+cx+d, vvedit' koefitsienty:\na,b,c,d:");
 scanf("%d%d%d%d",&a->x3,&a->x2,&a->x1,&a->x0);
 return;
}

void main()
{
 clrscr();
 pol *a;
 int x,res;

 vvod(a);
 printf("x="); scanf("%d",&x);

 res=a->x3*pow(x,3)+a->x2*pow(x,2)+a->x1*x+a->x0;

 printf("\nPri x=%d, polinom\n(%d)x3+(%d)x2+(%d)x+(%d)=%d",x,a->x3,a->x2,a->x1,a->x0,res);


 getch();
}