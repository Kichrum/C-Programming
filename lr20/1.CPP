#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct st{
	   int n;
	   st *sp;
	   } *last;



void add (int N,st*q,st*first)
{
 q=(st*)malloc(sizeof(st));
  if(first!=NULL) first=q;
   else last->sp=q;
	q->n=N;
   last=q;
  last->sp=NULL;
}

int view(st*first)
 { return first->n; }


void del(st*q,st*first)
{
 if(first==last) q=NULL;
  else q=first->sp;
 free(first);
 first=q;
}

void main()
{
 clrscr();
 int a,i;
 st *first=NULL,*first2=NULL,*q1,*q2;
 printf("Vvedit' chergu:");
 for(i=0;i<3;i++)
  {
   scanf("%d",&a);
   add(a,q1,first);
  }
  while (first!=NULL)
  {
   a=view(first);
   a*=a;
   add(a,q2,first2);
   del(q1,first2);
  }
  while (first2!=NULL)
  {
   printf("%d ",view(first2));
   del(q2,first2);
  }

 getch();
}