#include <stdio.h>
#include <conio.h>
#define n 10

void main()
{
 clrscr();

 float x[n],*q,s=0,k=0;
 int i;
 printf("Vvedit massiv:");
 for(i=0;i<n;i++) scanf("%f",x+i);

 for(q=x+0;q<x+n;q++)
  if(*q<0) {s+=*q;k++;}
 printf("Sr.ar.=%f", s/k);


 getch();
}