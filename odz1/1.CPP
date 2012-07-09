#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float X,a,b,ap,ak,da,Xmax;
 int s=1;
 printf("Pochatkove a=");
 scanf("%f",&ap);
 printf("Kintseve a=");
 scanf("%f",&ak);
 printf("delta a=");
 scanf("%f",&da);
 printf("b=");
 scanf("%f",&b);
 for(a=ap;a<=ak;a+=da)
 {
  if (a>=b && a>=0)
  {
   X=sqrt(3*a)+exp(1+a*b);
   printf("X=%f\n",X);
   if (s==1)
       {
       Xmax=X;
       s=0;
       }
   else if (Xmax<X) Xmax=X;
  }
  else if (a<b && a>=0)
  {
   X=pow(tan(abs(a+sqrt(b))),2);
   printf("X=%f\n",X);
    if (s==1)
       {
       Xmax=X;
       s=0;
       }
   else if (Xmax<X) Xmax=X;
  }
  else puts("ERROR!");
 }
 if(s==0) printf("Maximal'ne X=%f",Xmax);
 else printf("Maximalne X vidsutne!");
 getch();
}