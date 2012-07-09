// ---VARIANT #3---
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float u,s,x,e=0.0001;
 int n;
 s=0; n=1;
 printf("x="); scanf("%f",&x);
 u=x;

 while (fabs(u)>=e)
   {
    s+=u;
    u=u*(-1)*pow(x,2)*(2*n-1)/(2*n+1);
    n=n+1;

   }

 printf("arctg(x)=%f\n",atan(x));
 printf("S=%f\n"
 ,s);

 getch();
}