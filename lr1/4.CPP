#include <stdio.h>
#include <math.h>
void main()
{
 float S,a,x,y;
 puts("Vvedite S i a s novyh stro4ek");
 scanf("%f%f", &S, &a);
 if (S>0 && a>0)
 {
 x=(S-a)/2;
 y=x+a;
 printf("Pri a=%f S=%f rez y=%f x=%f", a,S,y,x);
  }
 else
 printf("Ne vycheslyaetsa pri S=%f a=%f\n",S,a);
 }