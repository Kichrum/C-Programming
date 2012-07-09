#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 const int n=20;
 int x[n];
 int imin, i,j, a;
 puts("Vvedite massiv x[n]");
 for(i=0;i<n;i++) scanf("%d",&x[i]);
 puts("do sortirovki:");
 for(i=0;i<n;i++) printf("%d ",x[i]);



for(i=0;i<n-1;i++)
{imin=i;
 for(j=i+1;j<n;j++)
  if(x[j]<x[imin]) imin=j;
  a=x[i];
  x[j]=x[imin];
  x[imin]=a;
}


   puts("\nResultat sortirovki vtorym sposobom:");
   for(i=0;i<n;i++)
    printf("%d ",x[i]);


 getch();
}