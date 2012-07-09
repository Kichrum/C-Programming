#include <stdio.h>
#include <conio.h>

void main()
{
 clrscr();

 char a[]="Tse ryadok. A tsya chastyna vidkydaets'a...",*b;

 for(b=a; *b!='\0'; b++) if(*b=='.') *b='\0';
 printf("Result: %s.",a);

 getch();
}