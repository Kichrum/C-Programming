#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{clrscr();
randomize();
int x[]={0}, z[]={0}, i, d,s,n;
printf("N="); scanf("%d",&n);
for(i=0;i<n;i++) x[i]=random(10);

printf("Maemo masyv:\nX=(");
for(i=0;i<n-1;i++) printf("%d;",x[i]);
printf("%d)\n\n",x[n-1]);



for(i=0,d=1,s=0;i<n;i++)
 if(i%2==0 && x[i]!=0)
 {
  d*=x[i];
  z[s]=x[i];
  s++;
 }



printf("Resultaty:\nZ=(");
for(i=0;i<s-1;i++) printf("%d;",z[i]);
printf("%d)\nDobutok=%d\n",z[s-1],d);




getch();}
