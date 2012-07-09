// ---VARIANT #25---
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
    u=-u*x*(3*n-2)/3*n;
    n=n+1;

   }
 printf("S=%f\n",s);

 printf("Tochniy otvet: %f\n",1/pow((x+1),1.0/3.0));

 getch();
}