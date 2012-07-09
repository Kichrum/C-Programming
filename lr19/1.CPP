#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct st
 { int n;
   struct st *ps;} stack,*last;

void input(last &p,int a)
{
 stack *q=(st*)malloc(sizeof(st));
 q->ps=p;
 q->n=a;
 p=q;
}

int output(last &p)
{
 int a;
 stack *q;
 a=p->n;
 q=p;
 p=p->ps;
 free(q);
 return a;
}

void main()
{
 clrscr();
 stack *p1=NULL, *p2=NULL;
 int a,n,i;
 printf("N="); scanf("%d",&n);
 printf("Vvedite %d chisel: ",n);
 for(i=0;i<n;i++)
  { scanf("%d",&a); input(p1,a); }

 printf("Udalit' element no "); scanf("%d",&a);
 if(a>n) { puts("ERROR! No elements deleted!"); }
  for(i=0;i<n;i++)
   {if(i!=n-a){
    input(p2,output(p1));
   }else output(p1);}
  output(p1);
  while(p2!=NULL)
   printf("%d ",output(p2));

 getch();
}