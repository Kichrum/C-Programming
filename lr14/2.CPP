#include<stdio.h>
#include<conio.h>

void vvod(int *a,int n);
void max(int *a,int n,int *M,int *M1);

void main(){
 clrscr();

 int a[10],max_n,max_zn;
 vvod(a,10);
 max(a,10,&max_n,&max_zn);
 printf("Maximalnyi element - %d, nomer - %d",max_n,max_zn);
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
void max(int *a,int n,int *M,int *M1)
{
 *M=0;
 for (int i=0;i<n;i++)
  if (a[i]>a[*M]) *M=i;
 *M1=a[*M];
}