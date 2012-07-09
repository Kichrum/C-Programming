#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct st
 { int ch;
   struct st *ps; } STACK, *LPSTACK;

void put(LPSTACK &p1, int w)  {
 STACK *q = (STACK*)malloc(sizeof(STACK));
 q->ps=p1;
 q->ch=w;
 p1 = q;
}

int views(STACK *p1) {
   int q=p1->ch;
   p1=p1->ps;
   return q;
}

void free_stack(STACK *p1){
 STACK *q;
 while (p1 != NULL)
 {
   q= p1;
   p1 = p1->ps;
   free(q);
 }
}

void main()
{
 clrscr();
  STACK *p=NULL,*p2=NULL;
  int a,i;
  for(i=0;i<6;i++)
   {
	scanf("%d",&a);
	put(p,a);
   }
  printf("\n\nbez 5-go:\n");
  i=0;
   while (p!=NULL)
	{
	 if(i!=2) put(p2,views(p));
	 i++;
	}
  while(p2!=NULL)
  printf("%d",views(p2));

  free_stack(p);
  free_stack(p2);
 getch();
}