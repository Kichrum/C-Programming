#include <stdio.h>
#include <conio.h>
#include<math.h>

void main()
{
 clrscr();

 const int n=2;
 float a[n][n],max,b[n][n];
 int i,j,imax,jmax;


//Zadaemo masiv:
 puts("Vvedit' matritsu A:");

 for (i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
  {
  printf("A(%d;%d)=",i,j);
  scanf("%f",&a[i][j]);
  }
 }

 puts("\nMaemo masiv:");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++) printf("%10.1f ",a[i][j]);
  printf("\n");
 }


//Variant 9:

max=a[0][0];

for(i=0;i<n;i++) for(j=0;j<n;j++)
{
 if(a[i][j]<0) a[i][j]=-1*a[i][j];
 if(fabs(a[i][j])>max) max=fabs(a[i][j]);
}
if (max==0) puts("ERROR! \"/0\""); else {
for(i=0;i<n;i++) for(j=0;j<n;j++)
{ b[i][j]=a[i][j]/max; }

printf("\n Matrits'a B otrymana dilennyam kojnogo\n elementu matritsi A na naybilschiy\n po modulu element matritsi A (%1.1f):\n",max);
for(i=0;i<n;i++)
{ for(j=0;j<n;j++) printf("%10f ",b[i][j]); printf("\n"); }
 }
 getch();
}