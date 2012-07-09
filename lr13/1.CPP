#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a[10][15],b[15][12],i,j;


void dob1(int c[10][15])
{
int d=1;

for(i=0;i<10;i++)
 {
 for(j=0;j<15;j++)
  if(c[i][j]<0) d*=c[i][j];
 printf("%d ",d);
 d=1;
 }
}

void dob2(int c[15][12])
{
int d=1;

for(i=0;i<15;i++)
 {
 for(j=0;j<12;j++)
  if(c[i][j]<0) d*=c[i][j];
 printf("%d ",d);
 d=1;
 }
}


void main()
{
 clrscr();
 randomize();


 printf("A=\n");
 for(i=0;i<10;i++) {
  for(j=0;j<15;j++)
  {a[i][j]=random(18)-9;
   printf(" %d",a[i][j]);}
  printf("\n");}

 printf("\nB=\n");

 for(i=0;i<15;i++) {
  for(j=0;j<12;j++)
   {b[i][j]=random(18)-9; printf(" %d",b[i][j]);}
   printf("\n");}

printf("\nDlya A:\n");
dob1(a);
printf("\nDlya B:\n");
dob2(b);

 getch();
}