#include <stdio.h>
#include <math.h>
void main()
{
 float a,x,k=1.25,y;
 puts("Zna4enie a i x");
 scanf("%f%f",&a,&x);
 y=a*pow(cos(k*x),2);
 printf("a=%f x=%f rezultat y=%f\n",a,x,y);
 puts("Thank you! Good Bye!");
  }