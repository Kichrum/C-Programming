#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct pol
{
 int a;
 int b;
 int c;
 int d;
}pol;

void vvod(pol*p)
{
 printf("Nehay polinom: ax3+bx2+cx+d, vvedit' koefitsienty:\na,b,c ta d:");
 scanf("%d%d%d%d",&p->a,&p->b,&p->c,&p->d);
 return;
}

int s4et(pol*p,int x)
{
 int res;
 res=p->a*pow(x,3)+p->b*pow(x,2)+p->c*x+p->d;
 return res;
}

void main()
{
 clrscr();
 pol *p;
 int x,result;
 vvod(p);
 printf("x="); scanf("%d",&x);
 result=s4et(p,x);
 printf("\nPri x=%d, polinom\n",x);
 printf("(%d)x3+(%d)x2+(%d)x+(%d)=%d",p->a,p->b,p->c,p->d,result);
 getch();
}