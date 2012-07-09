#include <stdio.h> 
#include <stdlib.h> 
typedef struct st 
 { int ch; 
   struct st *ps; } STACK, *LPSTACK; 
 
void put(LPSTACK &p1, int w)  { 
 STACK *q = (STACK*)malloc(sizeof(STACK)); 
 q->ps = p1; 
 q->ch=w; 
 p1 = q;
} 
 
void views(STACK *p1) {
 while (p1 != NULL)
 {
   printf("%d\n", p1->ch);
   p1 = p1->ps;
 }
}

int viewst(STACK *p1) {
  int q=p1->ch;
  p1 = p1->ps;
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
  STACK *p=NULL,*p1=NULL;
  int a,i;
  for(i=0;i<6;i++)
   {
	scanf("%d",&a);
	put(p,a);
   }

  while (p!=NULL)
   {
	put(p1,viewst(p));
   }

  views(p1);
  free_stack(p);
  free_stack(p1);
}
