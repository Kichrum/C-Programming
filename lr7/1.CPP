#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 const int n=20;
 int x[n];

 int a;
 int i,k;
 puts("Vvedite massiv x[n]");
 for(i=0;i<n;i++) scanf("%d",&x[i]);
 puts("do sortirovki:");
 for(i=0;i<n;i++) printf("%d ",x[i]);


 for(k=1;k<n;k++)
  for(i=0;i<n-k;i++)
   if(x[i]>x[i+1])
   {a=x[i];
   x[i]=x[i+1];
   x[i+1]=a;}
   puts("\nResultat sortirovki pervym sposobom:");
   for(i=0;i<n;i++)
    printf("%d ",x[i]);


 getch();
}