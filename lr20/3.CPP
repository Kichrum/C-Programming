#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 5
struct st {
		int n;
		st *sp;
};

void Add (st **first,st **last,int a) {
  st*q;
  q=(st*)malloc(sizeof(st));
   if (first==NULL) *first=q;
   else (*last)->sp=q;
		*last= q;
		q->n=a;
		(*last)->sp=NULL;
//	free(q);
 }
  int View(st **first)
   {
   return (*first)->n; }

void Delete(st*first,st*last)
 {
  st*q;
  if (first==last) q=NULL;

	 else q=first->sp;

	 free(first);
  first=q;
//  free(q);
   }

   void main() {
   clrscr();
   int i,k=1;
   st *first1=NULL,*first2=NULL,*last1,*last2;
   printf("Vvedit': ");
	for(i=0;i<N;i++)
	 {  scanf("%d",&k);
		Add(&first1,&last1,k);
	 }

	 /*
while (first1!=NULL)  {
	 k=View(first1);

   if (k>0) Add(first2,last2,k);
   Delete(first1,last1);

   }   */

while (first1!=NULL)  {
	 k=View(&first1);

	printf("%d",k);
	Delete(first1,last1);
	}
	getch();
 }