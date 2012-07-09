#include <stdio.h>
#include <math.h>
void main()
 {
 float x,y,a;
 puts ("Zna4enie a i x");
 scanf("%f%f",&a, &x);
 if ((a-x)>0 && cos(x)!=0)
 {
 y=log(a-x)/cos(x);
 printf("Pri a=%f x=%f rezultat y=%f\n", a,x,y);
 puts ("Otvet polu4en uspeshno!");
  }
 else
 printf("Ne vychislyaetsa pri a=%f x=%f\n",a,x);
  }