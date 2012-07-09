#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sklad
	{
	 char art[2];
	 char name[20];
	 int kil;
	 float vart;
	 struct sklad *next;
	}vzut;



void vved(vzut *a,int &n)
{
// vzut *q=(vzut*)malloc(sizeof(vzut));

 int i;
 printf("Skilky par vy bazhaete vvesty v bazu danyh? N=");
 scanf("%d",&n);
 printf("Vvedit' cherez probil:\nartykul nazva kil'kist' vartist':\n");
 for(i=0;i<n;i++)
  {
   printf("%d: ",i+1);
   scanf("%s%s%d%f",&a->art,&a->name,&a->kil,&a->vart);
   a->next=a;
//   a=q;
//   a->prev=a->next;
  }
}


void vyved(vzut*a,int n)
{
 vzut *q=(vzut*)malloc(sizeof(vzut));
 *q=*a;
 int i=0;
 printf("Vyvedennya:\n");
// while(q!=NULL)
 for(i=0;i<n;i++)
  {
   printf("\n%s,\"%s\", ",q->art,q->name);
   printf("%d par po %4.2f UAH",q->kil,q->vart);
//  q->prev=q;
   q=q->next;
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
 vzut *a=NULL;
 int n;
  float *q; scanf("%f",&q); *q=a->vart;

 vved(a,n);
 vyved(a,n);
// sart(a,n);
// sdam(a,n);


 getch();
}