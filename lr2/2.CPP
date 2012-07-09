#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float y,x,k,b,c;
 puts("Vvedite k:");
 scanf("%f",&k);
 puts("Vvedite b:");
 scanf("%f",&b);
 puts("Vvedite c:");
 scanf("%f",&c);
 puts("Vvedite x:");
 scanf("%f",&x);
 if((fabs(pow(cos(c*x),2))+c)/exp(x)>=0)
 {
 y=pow(pow(atan(x+b),3)/pow(x,2*k+1),1.0/5.0) - pow((fabs(pow(cos(c*x),2))+c)/exp(x),1.0/2.0);
 printf("Otvet: y=%f",y);
 }
 else
 puts ("Ne verno zadany chisla!");
 getch();
}