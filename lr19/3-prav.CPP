#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>

typedef struct st
 { int ch;
   struct st *ps; } STACK, *LPSTACK;

void put(LPSTACK&,int);
void views(STACK*);
void free_stack(STACK*);

void main()
{
 clrscr();
  STACK *p1=NULL,*p2=NULL;
  int a,i;
  printf("Vvedit' 10 chisel: ");
  for(i=0;i<10;i++)
   {
	scanf("%d",&a);
	if(a%2==0) put(p1,a);
	else put(p2,a);
   }
  printf("\nParni: ");
  views(p1);
  printf("\nNeparni: ");
  views(p2);
  free_stack(p1);
  free_stack(p2);
 getch();
}

void put(LPSTACK &p, int w)  {
 STACK *q=(STACK*)malloc(sizeof(STACK));
 q->ps = p;
 q->ch=w;
 p=q;
}

void views(STACK *p) {
 if (p==NULL) printf("vidsutni");
 else while (p!=NULL)
 {
   printf("%d ", p->ch);
   p=p->ps;
 }

}

void free_stack(STACK *p){
 STACK *q;
 while (p != NULL)
 {
   q=p;
   p=p->ps;
   free(q);
 }
}

