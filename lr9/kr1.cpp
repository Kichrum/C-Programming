#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
 clrscr();
 randomize();

 int a[7],i,d=0,*q;
 for(i=0;i<7;i++) a[i]=random(200)-100;
 printf("Maemo masyv:\nA=(");
 for(q=a+0;q<a+6;q++) printf("%d;",*q);
 printf("%d)\n",*(a+6));


 for(q=a+0;q<a+6;q++)
  if(*q%5==0) d+=pow(*q,2);
 printf("Vidpovid': %d",d);

 getch();
}