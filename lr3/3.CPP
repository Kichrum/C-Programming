#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float z,x,xmin=1,dx=0.5,xmax=6;
 for(x=xmin;x<=xmax;x+=dx)
 {
  z=sin(x)+cos(x);
  printf("x=%1.1f => z=%f\n",x,z);
 }
 getch();
}