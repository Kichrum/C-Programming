#include <stdio.h>
#include <conio.h>

void main()
{
 clrscr();

 char *a,*b;
 printf("Ryadok: ");
 gets(a);

 for(b=a; *b!='\0'; b++) if(*b=='.') *b='\0';
 printf("Result: %s.",a);

 getch();
}