#include <stdio.h>
#include <conio.h>

#define n 10

void main()
{
 clrscr();


 float x[n],*q,d=1;
 int i;
 printf("Vvedit' masiv:");
 for(i=0;i<n;i++)
  scanf("%f",x+i);

 for(q=x+0;q<x+n;q++) printf("%f\n",*q);

 for(q=x+0;q<x+n;q++) if(*q-5>3) d*=*q;
 printf("\nDobutok=%f",d);





 getch();
}