#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()

{
clrscr();

float f,x;
int a=-2,b=-5.2,c=6;
scanf("%f",&x);
f=(exp(a*x)+2*log(b+c))/atan(b*x) +a*b;
printf("%f",f);

getch();

}