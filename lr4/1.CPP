#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float u,s,x,e=0.0001;
 int n;
 u=1; s=0; n=1;
 printf("x="); scanf("%f",&x);
 while (fabs(u)>=e)
   {
    s=s+u;
    u=u*(-x)/n;
    n=n+1;

   }
 printf("S=%g\n",s);
 printf("exp(-x)=%g\n",exp(-x));

 getch();
}