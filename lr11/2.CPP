#include <stdio.h>
#include <conio.h>


void main()
{
 clrscr();

int i,j,a;
printf("Kil'kist' studentiv: N="); scanf("%d",&a);
printf("Student # Prizvysche Imya Grupa r.n. Seredniy_bal:\n");



typedef struct person {
 char f[20]; //Family
 char n[20]; //Name
 char g[5];  //Group
 int y;      //Year
 char b[5];  //Bal
} Pers;

Pers arr[]={0};


for(i=0;i<a;i++)
{
 printf("Student-%d: ",i+1);
 scanf("%s %s %s %d %s",&arr[i].f,&arr[i].n,&arr[i].g,&arr[i].y,&arr[i].b);
}


Pers ar[]={0};
for (i=0,j=0;i<a;i++)
 if (arr[i].y<=1989) { ar[j]=arr[i]; j++; }
printf("Result:\n");
for(i=0;i<j;i++)

 printf("%s %s, Grupa %s, %dr.n., Sredniy bal: %s\n",ar[i].f,ar[i].n,ar[i].g,ar[i].y,ar[i].b);

 getch();
}