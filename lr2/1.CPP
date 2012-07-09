#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float f,x;
 const a=5,b=-3,c=4.5;
 puts("Vvedite x:");
 scanf("%f",&x);
 if(b*x>0)
 {
 f=(pow(b,c)+4*pow(tan(a),-1)*x)/log(b*x);
 printf("Otvet: %f",f);
 }
 else
 puts ("x doljno bit' men'she 0!");
 getch();
}