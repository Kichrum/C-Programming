#include <stdio.h>
#include <conio.h>


void main()
{
 clrscr();


struct person {
 char f[20]; //Family
 char n[20]; //Name
 int g;      //Group
 int y;      //Year
 float b;    //Bal
};
struct person arr[4]={{"Ivanoff","Ivan",1,1989,4.0},
 {"Petroff","Petro",2,1990,4.3},
 {"Askoldov","Uriy",2,1987,3.9},
 {"Suslik","Sergey",1,1991,5.0}};
int i,j=0;
struct person ar[4]={0};
for (i=0;i<4;i++)
 if (arr[i].y<=1989) { ar[j]=arr[i]; j++; }
printf("Result:\n");
for(i=0;i<j;i++)

 printf("%s,%s,Gruppa %d,%d,%1.1f\n",ar[i].f,ar[i].n,ar[i].g,ar[i].y,ar[i].b);

 getch();
}