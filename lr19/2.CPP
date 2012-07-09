#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct st
 { int ch[10];
   struct st *ps;} STACK;
 STACK *p1=NULL, *p2=NULL, *q;

void putinstack(STACK *p,int w,int i)
{
 q=(st*)malloc(sizeof(st));
 q->ps=p;
 q->ch[i]=w;
 p=q;
}

int viewstack(STACK *p,int i)
{
 if (p==NULL) return -1;
 return p->ch[i];
}

void deletestack(STACK *p)
{
 q=p;
 p=q->ps;
 free(q);
}

void clearstack(STACK *p)
{
 while(p!=NULL)
  deletestack(p);
}

int main()
{
 clrscr();
 int a[10],i,j,k;
 printf("Vvedit 10 chisel:");

 for(i=0;i<10;i++)
  scanf("%d",&a[i]);


 for(i=0,j=0,k=0;i<10;i++)
  {
   if(a[i]%2==0) {putinstack(p1,a[i],j); j++;}
   else {putinstack(p2,a[i],k); k++;}
  }
 puts("\nParni:");
 for(i=0;i<10;i++)
  printf("%d",viewstack(p1,i));
 puts("\n\nNeparni:");
 for(i=0;i<10;i++)
  printf("%d",viewstack(p2,i));


 clearstack(p1);
 clearstack(p2);
 getch();
 return 0;
}