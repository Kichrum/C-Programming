#include <stdio.h>
#include <math.h>
#include <conio.h>
void main()
{
 clrscr();
  float a, b, alpha,S,P;
  puts("a=");
  scanf("%f",&a);
  puts("b=");
  scanf("%f",&b);
  puts("alpha=");
  scanf("%f",&alpha);
  if (a>b && alpha<3.14/2)
   {
    P=a+b+((a-b)/cos(alpha));
    S=((a+b)/2)*(((a-b)/2)/cos(alpha))*sin(alpha);

    printf("P=%f, S=%f",P,S);
   }
  else
  puts("Error! Must a>b and alpha < Pi/2 !");
 getch();
}