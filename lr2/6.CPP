#include <stdio.h>
#include <math.h>
#include <conio.h>
void main()
{
 clrscr();
  float R=1.2,x,y;
  puts("x=");
  scanf("%f",&x);
  puts("y=");
  scanf("%f",&y);
  if (y<=0 && R>=sqrt(pow(x-1.5,2)+pow(y-0,2)))
   {
    puts("TRUE");
   }
  else
  puts("FALSE");
 getch();
}