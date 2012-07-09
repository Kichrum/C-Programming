#include<stdio.h>
#include<conio.h>


void vvod(int *a,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("#%d=",i);
  scanf("%d",a+i);
 }
}

int max(int *a,int n)
{
 int i,m;
 m=0;
 for(i=0;i<n;i++)
  if(a[i]>a[m]) m=i;
 return m;
}

void main()
{
 clrscr();
 int a[10],mel,mno;
 vvod(a,10);
 mno=max(a,10);
 mel=a[mno];

 printf("Max element - %d, ego nomer - %d",mel,mno);

 getch();
}
