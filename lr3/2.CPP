#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float z,x,xmin,dx,xmax;
 puts("xmin=\nxmax=\ndx=\n");
 scanf("%f%f%f",&xmin,&xmax,&dx);
 x=xmin;
 do
 {
  z=sin(x)+cos(x);
  printf("x=%1.1f => z=%f\n",x,z);
  x+=dx;
 }
 while(x<=xmax);
 getch();
}