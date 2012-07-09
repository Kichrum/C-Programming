#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
 {
	 char art[2];
	 char name[20];
	 int kil;
	 float vart;
	 struct list *next;
 }list;
/*
list add(list *first,list *q)
{
 list *vsp;
 vsp=(list*)malloc(sizeof(list));

 *vsp->art=*q->art;
 *vsp->name=*q->name;
 vsp->kil=q->kil;
 vsp->vart=q->vart;

 vsp->next=first;
 first=vsp;
 return *first;
} */

list vved(list *a)
{
 int i,n;
 list*q;
 q=(list*)malloc(sizeof(list));
 printf("Skilky par vy bazhaete vvesty v bazu danyh? N=");
 scanf("%d",&n);
 printf("Vvedit' cherez probil:\nartykul nazva kil'kist' vartist':\n");


 for(i=0;i<n;i++)
  {
   printf("%d: ",i+1);
   scanf("%s%s%d%f",&q->art,&q->name,&q->kil,&q->vart);
   q->next=a;
   a=q;

  }
 return *a;
}


void vyved(list*a)
{
 list*q;
 int i=0;
 q=a;
 printf("Result:\n");
 while(q!=NULL)
 {
  i++;
  printf("\nNo.%d: %s,\"%s\", ",i,q->art,q->name);
  printf("%d par po %4.2f UAH",q->kil,q->vart);
  q=q->next;

 }

}


void main()
{
 clrscr();
 list *vzut=NULL;
 float *q=&vzut->vart;

 *vzut=vved(vzut);
 vyved(vzut);



 getch();
}