#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float x,y;
 puts("x=");
 scanf("%f",&x);
 puts("y=");
 scanf("%f", &y);

 if((y<=0) && (y>=-2*x-3) && (y>=2*x-3))
 puts("TRUE");

 else
 puts ("FALSE");
 getch();
}