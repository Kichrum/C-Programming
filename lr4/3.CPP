#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float f,a,b,c,ap,ak,da;
 printf("Pochatkove a=");
 scanf("%f",&ap);
 printf("Kintseve a=");
 scanf("%f",&ak);
 printf("delta a=");
 scanf("%f",&da);
 printf("b=");
 scanf("%f",&b);
 printf("c=");
 scanf("%f",&c);
 if (ap<0 && ak>0 && c!=0 && tan(c)!=0 && cos(c)!=0)
{
 a=ap;
 while(a<=ak)
 {
   f=pow(b/c+sin(a),1.0/5.0)/tan(c);
   printf("a=%f => f=%f\n",a,f);
   a+=da;
 }
}
else puts("ERROR!");
 getch();
}