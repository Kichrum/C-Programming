#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 const int n=20;
 int b[n],i,j,c;
 puts("Vvedite massiv:");
 for(i=0;i<n;i++) scanf("%d",&b[i]);
 puts("do sortirovki:");
 for(i=0;i<n;i++) printf("%d ",b[i]);


  for(i=1;i<n;i++)
  {
  c=b[i];
  for (j=i-1;j>=0 && b[j]>c;j--)
   b[j+1]=b[j];
   b[j+1]=c;
   }

   puts("\nResultat sortirovki tretim sposobom:");
   for(i=0;i<n;i++)
    printf("%d ",b[i]);


 getch();
}