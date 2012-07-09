#include<stdio.h>
#include<conio.h>

void vvod(int *a,int n);
int max(int *a,int n);

void main(){
 clrscr();

 int a[10],m;
 vvod(a,10);
 m=max(a,10);
 printf("Maximalnyi element - %d, nomer - %d",a[m],m);
 getch();

}

void vvod(int *a,int n)
{
 for (int i=0;i<n;i++)
  {
   printf("%d: ",i);
   scanf("%d",a+i);
  }
}

int max(int *a,int n)
{
 int M=0;
 for (int i=0;i<n;i++)
  if (a[i]>a[M]) M=i;
 return M;
}