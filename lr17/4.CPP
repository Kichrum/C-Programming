#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct size{
	     int ni;
	     int nj;
	     int *a[10];
	     }size;

void main()
{
 clrscr();
 size s;
 int i,j;
 printf("Ni="); scanf("%d",&s.ni);
 printf("Nj="); scanf("%d",&s.nj);
 randomize();
 for(i=0;i<s.ni;i++)
 s.a[i]=(int*) malloc(s.nj*sizeof(int));
 for(i=0;i<s.ni;i++)
 for(j=0;j<s.nj;j++)
 {
  *(s.a[i]+j)=random(18)-9;
  printf("%3d",*(s.a[i]+j));
  if((j+1)%s.nj==0)
   printf("\n");
 }
 for(i=0;i<s.ni;i++)
 free(s.a[i]);
 for(i=0;i<s.ni;i++)
 for(j=0;j<s.nj;j++)
 {
  printf("%3d",*(s.a[i]+j));
  if((j+1)%s.nj==0)
   printf("\n");
 }
 getch();
}