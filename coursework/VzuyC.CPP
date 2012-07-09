#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct sklad
	{
	 char art[2];
	 char name[20];
	 int kil;
	 float vart;
	 sklad *next;
	} *first=NULL, *last, *q;

void vved(int &n)
{
 int i;
 q=(sklad*)malloc(sizeof(sklad));



 printf("Skilky par vy bazhaete vvesty v bazu danyh? N=");
 scanf("%d",&n);
 printf("Vvedit' cherez probil:\nartykul nazva kil'kist' vartist':\n");
 for(i=0;i<n;i++)
  {
   if(first==NULL) first=q;
     else last->next=q;
   printf("%d: ",i+1);
   scanf("%s%s%d%f",&q->art,&q->name,&q->kil,&q->vart);
   last=q;
   last->next=NULL;
  }

}

void vyved(int n)
{
 sklad*q,*q1;
 q=first;
 int i=0;
// for(i=0;i<n;i++)
 while(q!=NULL)
 {
  printf("\nNo.%d: %s,\"%s\", ",i+1,q->art,q->name);
  printf("%d par po %4.2f UAH",q->kil,q->vart);
  if(q==last) q=NULL;
   else q1=q->next;
  free(q);
  q=q1;
  i++;
 }

}


/*
void sart(vzut *a,int n)
{
 char x[2];
 int b=0,i;
 printf("Vvedit poshukoviy artykul (D,C abo P): ");
 scanf("%s",&x);
 for(i=0;i<n;i++)
  if(strcmp(x,a[i].art)==0)
   {
    if(b==0)printf("\nZnaydeno!\n");
    printf("\nNo.%d: %s,\"%s\", ",i+1,a[i].art,a[i].name);
    printf("%d par po %4.2f UAH",a[i].kil,a[i].vart);
    b=1;
   }
 if(b==0)printf("Nema takogo...");
}

void sdam(vzut *a,int n)
{
// char x[2];
 int b=0,i;
 for(i=0;i<n;i++)
  if(strcmp("D",a[i].art)==0)
   {
    if(b==0)printf("\nZnaydeno take dams'ke vzuttya:");
    printf("\nNo.%d: \"%s\" %d par",i+1,a[i].name,a[i].kil);
    b=1;
   }
 if(b==0)printf("Nema takogo...");
}
*/
void main()
{
 clrscr();
 sklad *a=NULL;
 int n;
 float *q=&a->vart;


 vved(n);
 vyved(n);
// sart(a,n);
// sdam(a,n);


 getch();
}