#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{clrscr();
randomize();

int p[3][3],i,j,d,k1,k2;

for(i=0;i<3;i++) for(j=0;j<3;j++) p[i][j]=random(10);

printf("Maemo matritsu:\n\n  P[3*3]:\n");
for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
   printf(" %d  ",p[i][j]);
  printf("\n");
 }
d=0;

for (i=0;i<3;i++)
 {
  k1=(i+1<3)?i+1:i-2;
  k2=(i-1<0)?i+2:i-1;
  d=d+p[i][0]*(p[k1][1]*p[k2][2]-p[k2][1]*p[k1][2]);
 }

printf("\ndetP=%d",d);

getch();}
