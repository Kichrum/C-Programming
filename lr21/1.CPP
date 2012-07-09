#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct list
 { int n;
   struct list *next;
 }LIST,*ALIST;

void put(ALIST&a,int b)
{
 LIST *q=(LIST*)malloc(sizeof(LIST));
// q=a;
 q->next=a;
 q->n=b;
 a=q;
}

int view(LIST*a,int b)
{
 int i;
 LIST *q;
 q=a;
 a=a->next;
// printf("_%d_",a->n);
 for(i=0;i<b;i++) //{
  q=q->next;
//  printf("%d ",q->n); }
 return q->n;
}

int srch(ALIST&a,int b)
{
 LIST *q,*q2;
 int min,i;
 q=a;
 min=q->n;
 for(i=0;i<b;i++)
 {
  q=q->next;
  if(q->n<min) min=q->n;//printf("\n%d, %d;",min,q->n);}
 }
 q=a;
 for(i=0;i<b;i++) {put(a,q->n);q=q->next;}
 q=a;
 while(a!=NULL) a=a->next;
 printf("min: %d\n ",min);

 for(i=0;i<b;i++)
 {

  if(min!=q->n) { put(a,q->n); q=q->next; }
  if(min==q->n) {
   put(a,q->n);
   q=q->next->next;
/*   put(a,q->n);
   printf(" _%d_",a->n);
   q=q->next;*/
   }
/*  q=a;
  while(a!=NULL) a=a->next;
  for(i=0;i<b-1;i++) {put(a,q->n);q=q->next;}*/



  printf("\n%d. ",a->n);
 }
 return min;
}

void main()
{
 clrscr();
 LIST *a;
 int b,n,i;
 printf("N="); scanf("%d",&n);
 printf("Vvedit spisok: ");
 for(i=0;i<n;i++)
  {
   scanf("%d",&b);
   put(a,b);
  }
 srch(a,n);
//   printf("%d",a->next->n);
  //  view(a,4);

 for(i=0;i<n;i++)
  printf("%d ",view(a,i));


 getch();
}
