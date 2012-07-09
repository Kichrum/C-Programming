#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#define N 5
typedef struct st
{ int n;
  struct st *ps;
  }ST;
void Add(ST**first, ST**last,int n)
{
 ST*q=(ST*)malloc(sizeof(ST));
 if(*first==NULL) *first=q;
 else
 (*last)->ps=q;
 q->n=n;
 *last=q;
 (*last)->ps=NULL;

}

int view(ST**first,ST**last)
{
 int n;
 n=(*first)->n;
 ST *q;
 if(*first==*last) q=NULL;
 else q=(*first)->ps;
 free(*first);
 *first=q;
 return n;
}

void main()
{
 clrscr();
 int k,i;
 ST*first1=NULL,*last1=NULL,*first2=NULL,*last2=NULL;
 printf("Vvedit: ");
 for(i=0;i<N;i++)
 {
  scanf("%d",&k);
  Add(&first1,&last1,k);
 }
  printf("Vidpovid': ");
  while(first1!=NULL)
  {
   k=view(&first1,&last1);
   if(k>0) Add(&first2,&last2,k);
  }

  while(first2!=NULL)
  {printf("%d ",view(&first2,&last2));}


 getch();
}