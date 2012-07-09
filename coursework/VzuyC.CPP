#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct db
 {
  char art[2];
  char name[20];
  int kil;
  float vart;
 }DB;
typedef struct list
 {
  DB db;
  struct list *next;
 }LIST;

LIST *list=NULL;

void add(LIST*last)
{
 LIST *q;
 int n,i;
 q=(LIST*)malloc(sizeof(LIST));
 printf("Skilky par vy bazhaete vvesty v bazu danyh? N=");
 scanf("%d",&n);
 printf("Vvedit' cherez probil:\nartykul nazva kil'kist' vartist':\n");
 fflush(stdin);
 for(i=1;i<=n;i++)
 {

  printf("%d: ",i);
  scanf("%s%s%d%f",&q->db.art,&q->db.name,&q->db.kil,&q->db.vart);
  q->next=NULL;
  if(list==NULL) list=q;
   else last->next=q;
 }
   free(q);

}

LIST print(void)
{
 int i=1;
 LIST *q=NULL;
 q=list;
 while(q!=NULL)
 {
  printf("\nNo.%d: %s,\"%s\", ",i,q->db.art,q->db.name);
  printf("%d par po %4.2f UAH",q->db.kil,q->db.vart);
  i++;
 }
}

void freelist(void)
{
 LIST *q=list;
 while (q!=NULL)
 {
  list=list->next;
  free(q);
  q=list;
 }
}

void main()
{
 clrscr();


 LIST *end=NULL;
  float *q=&end->db.vart;
// do{
//  end=
  add(end);
  end=NULL;
// }while(end!=NULL);
 puts("Result:");
 print();
 freelist(); puts("Vydaleno...");
 getch();
}

