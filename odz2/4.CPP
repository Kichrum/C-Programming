#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{clrscr();
randomize();
const int m=5,n=3;
int b[m][n],a[m][n],i,j,s;

for(i=0;i<m;i++) for(j=0;j<n;j++) b[i][j]=random(10);

printf("Maemo matritsu:\n\n  B[%d][%d]:\n",m,n);
for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
   printf(" %d  ",b[i][j]);
  printf("\n");
 }

for(i=0;i<m;i++)
 for(j=0;j<n;j++)
 {
  if(i!=1) a[i][j]=b[i][j];
  else {
  s=b[0][j]+b[m-1][j];
  a[i][j]=s;
       }
 }




printf("\nResultat:\n\n  B[%d][%d]:\n",m,n);
for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
   printf(" %d  ",a[i][j]);
  printf("\n");
 }

getch();}
