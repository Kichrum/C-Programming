#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();
 float z,x,xmin=1,dx=0.5,xmax=6;
 x=xmin;
 while(x<=xmax)
 {
  z=sin(x)+cos(x);
  printf("%f\n",z);
  x+=dx;
 }


 getch();
}