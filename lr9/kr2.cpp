#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
 clrscr();
 randomize();

 int a[4][5],i,j,min=100;
 for(i=0;i<4;i++) for(j=0;j<5;j++) a[i][j]=random(100);
 printf("Maemo masyv:\n");
 for(i=0;i<4;i++)
  {
   for (j=0;j<5;j++) printf(" %d  ",a[i][j]);
   printf("\n");
  }

 for(i=0;i<4;i++)
  if(abs(a[i][3])<min) min=a[i][3];

printf("min=%d",min);



 getch();
}