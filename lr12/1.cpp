#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int i,s1=0,s2=0,x[50],y[60];
void Sum();
void main()
{
 clrscr();
 randomize();
  for (i=0;i<50;i++) x[i]=random(20)-10;
  for (i=0;i<60;i++) y[i]=random(20)-10;
 Sum();
 printf("x(50)=(");
  for (i=0;i<50;i++) printf("%d;",x[i]);
 printf("%d)\n\ny(60)=(",x[50]);
  for (i=0;i<60;i++) printf("%d;",x[i]);
  printf("%d)",y[60]);
 float z=float(s1+s2)/2;
 printf("\n\n\nz=(%d+(%d))/2=%1.1f",s1,s2,z);
 getch();
}
void Sum()
{
 for (i=0;i<50;i++) if(x[i]>0) s1+=x[i];
 for (i=0;i<60;i++) if(y[i]<0) s2+=y[i];
}