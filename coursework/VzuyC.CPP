#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
/*#include<string.h>
#define Esc 0*1b
*/
typedef struct db
	{
	 char art[2];
	 char name[20];
	 int kil;
	 float vart;
	} DB;

typedef struct list
	{
	 DB db;
	 struct list *next;
	} LIST;

LIST *first=NULL,*last;
FILE *f;

int menue(void);

void vved(void)
{
 LIST *q;
 int k;
 q=(LIST*)malloc(sizeof(LIST));
 if (first==NULL)
  {
   first=q;
   first->next=NULL;
   k=0;
  }
  else
   {
	last->next=q; q->next=NULL; last=q;
	fprintf(f,"\n");
	k=1;
   }
 puts("\tNoviy zapis' v bazu danyh.");
 printf("Artykul (C,D abo P): ");
  scanf("%s",&q->db.art);
  fprintf(f,"%s ",q->db.art);

 printf("Nazva: ");
  scanf("%s",&q->db.name);
  fprintf(f,"%s ",q->db.name);

 printf("Kil'kist': ");
  scanf("%d",&q->db.kil);
  fprintf(f,"%d ",q->db.kil);

 printf("Vartist': ");
  scanf("%f",&q->db.vart);
  fprintf(f,"%f",q->db.vart);

  if(k!=0) menue();

}



int readfile(void)
{
 LIST *q=(LIST*)malloc(sizeof(LIST));

 if (q==NULL)
  {
   printf("Nemae pam'ati!\n");
   getch();
   exit(0);
  }

 if (first==NULL)
  {
   first=q;
   first->next=NULL;
  }
  else {last->next=q; q->next=NULL;}

 fscanf(f,"%s%s%d%f",&q->db.art,&q->db.name,&q->db.kil,&q->db.vart);

 last=q;
 return 0;
}

void vyved(void)
{
 clrscr();

 LIST *q=first;

  int i=1,max=3;
  printf("Baza danyh:");
  while (q!=NULL)
   {
	printf("\nNo.%d: %s \"%s\" - %d par po \t%4.2f UAH",i,q->db.art,q->db.name,q->db.kil,q->db.vart);
	if(i%max==0)
	 {
	  puts("\nNe vmischaetsya! Press any key.");
	  getch();
	  clrscr();
	  printf("Baza danyh:");
	 }
	q=q->next;
	i++;

   }
  getch();
  menue();
}

//void search

void clearlist(void)
{
 LIST *p;
 while (first!=last)
  {
   p=first;
   first=first->next;
   free(p);
  }
 free(first);
}

void sart(void)
{
 clrscr();
 char x[2];
 int i=1,k=0,j=1,max=3;
 printf("Artykul (D, C abo P): "); scanf("%s",&x);
 LIST *q=first;

  while (q!=NULL)
   {
    if(strcmp(x,q->db.art)==0)
     {
      k=1;
      printf("\nNo.%d: \"%s\" - %d par po \t%4.2f UAH",i,q->db.name,q->db.kil,q->db.vart);
      if(j%max==0)
	 {
	  puts("\nNe vmischaetsya! Press any key.");
	  getch();
	  clrscr();
	 }
      j++;
     }
    q=q->next;
    i++;

   }
  if(k==0) puts("Nichogo ne znaydeno!");
  getch();
  menue();
}

void sdam(void)
{
 clrscr();
 int i=1,k=0,j=1,max=3;
 LIST *q=first;

  while (q!=NULL)
   {
    if(strcmp("D",q->db.art)==0)
     {
      k=1;
      printf("\nNo.%d: \"%s\" - %d par",i,q->db.name,q->db.kil);
      if(j%max==0)
	 {
	  puts("\nNe vmischaetsya! Press any key.");
	  getch();
	  clrscr();
	 }
      j++;
     }
    q=q->next;
    i++;

   }
  if(k==0) puts("Nichogo ne znaydeno!");
  getch();
  menue();


}


int menue(void)
{
 clrscr();
 int n=0;
 printf("Oberit' potribnu diyu:\n1.Poshuk po artykulu\n2.Asortiment dams'kogo vzuttya\n");
 printf("3.Vyvesty bazu danyh\n4.Dodaty element\n5.Viyty\n");
 scanf("%d",&n);
 switch (n)
  {
   case 1: sart(); break;
   case 2: sdam(); break;
   case 3: vyved(); break;
   case 4: clrscr(); vved(); break;
   case 5: return 1; break;
  }
 return 0;
}



int main(void)
{
 clrscr();
 float w; sscanf("1","%f",&w);


 if ((f=fopen("sklad.txt","r+"))==NULL)
  {
   fclose(f);
   if((f=fopen("sklad.txt","wt"))==NULL)
     {puts("Ne stvoreno fayla!"); getch(); return 1;}
   puts("Fayl vidsutniy! Vvedit' hochab odyn zapys.\n");
   vved();
   clearlist();
   fclose(f);
   f=fopen("sklad.txt","r+");
  }

 while (!feof(f))
		    readfile();

 menue();

 clearlist();


 fclose(f);
 return 0;
}






/*


void Ramka(int x,int y,int x1,int y1,int x2,int y2)
{
clrscr();

window(1,1,80,25);

textcolor(14);
textbackground(0);
gotoxy(x1,y1);
putch(201);
for(x=x1+1;x<x2;x++)
  putch(205);
putch(187);
for(y=y1+1;y<y2;y++)
 {
   gotoxy(x1,y);
   if (y==y1+4||y==y1+8||y==y1+12||y==y1+16) putch(204); else putch(186);
   gotoxy(x2,y);
   if (y==y1+4||y==y1+8||y==y1+12||y==y1+16) putch(185); else putch(186);
 }

gotoxy(x1,y2);
putch(200);

for(x=x1+1;x<x2;x++)
  putch(205);
putch(188);

int i;
for(i=1,y=y1+4;i<5;i++,y+=4)
 {
  gotoxy(x1+1,y);
  for(x=x1+2;x<x2+1;x++)
    putch(205);
 }

}


int Menu(FILE *f)
{
int x1=3,x2=60,y1=3,y2=23;
int x,y;
Ramka(x,y,x1,y1,x2,y2);
Punkt(0,x1+1,y1+1);

x=x1+2;y=y1+2;
gotoxy(x,y);
char c=0;
int v=0;

while (v==0)
 {
 c=getch();
 if (c==27) {exit(0);}

  switch (c)
    {
     case 80://vniz
	if (y<y2-4)
	{
	gotoxy(x,y+=4);
	if (y==y1+2)  Punkt(1,x1+1,y1+1);
	if (y==y1+6)  Punkt(2,x1+1,y1+1);
	if (y==y1+10) Punkt(3,x1+1,y1+1);
	if (y==y1+14) Punkt(4,x1+1,y1+1);
	if (y==y1+18) Punkt(5,x1+1,y1+1);
	gotoxy(x,y);
	}break;

     case 72://vverx
	 if (y-4>y1)
	 {
	 gotoxy(x,y-=4);
	 if (y==y1+2)  Punkt(1,x1+1,y1+1);
	 if (y==y1+6)  Punkt(2,x1+1,y1+1);
	 if (y==y1+10) Punkt(3,x1+1,y1+1);
	 if (y==y1+14) Punkt(4,x1+1,y1+1);
	 if (y==y1+18) Punkt(5,x1+1,y1+1);
	 gotoxy(x,y);
	 }break;

     case 13:
	{
	if (y==y1+2) {v=1;break;}
	if (y==y1+6) {v=2;break;}
	if (y==y1+10) {v=3;break;}
	if (y==y1+14) {v=4;break;}
	if (y==y1+18) {v=5;break;}
	}
    }


 }

switch (v)
  {
    case 1: PrintList(f); break;

     case 2: AddRecord(f); break;

     case 3: FirstYmova(f); break;

     case 4: SecondYmova(f);break;

     case 5: return 0;break;

  }
return 1;
}


void FirstYmova(FILE *f)
{
clrscr();
LIST *q=first;
int i=0;
char city[20];
printf("Vvedit misto:");
scanf("%s",&city);
printf("\nChas vidpravlenn9 litakiv y misto %s :",city);
while (q!=NULL)
 {
  if (strcmp(q->zapis.misto,city)==0)
   {printf(" \n - %s",q->zapis.chas_v);i++;}
  q=q->next;
 }
 if (i==0) printf("\nLitakiv nemae");
 getch();
 Menu(f);
}

void SecondYmova(FILE *f)
{
clrscr();
LIST *q=first;
int i=0;
char city[20];
char ch_v[20];
printf("Vvedit misto:");
scanf("%s",&city);
printf("Vvedit chas vidlioty:");
scanf("%s",&ch_v);

printf("\nK-st` vilnix mistc:");
while (q!=NULL)
 {
  if (strcmp(q->zapis.misto,city)==0&&strcmp(q->zapis.chas_v,ch_v)==0)
    {printf(" \n %s - %s - %d",q->zapis.misto,q->zapis.chas_v,q->zapis.k);i++;}
  q=q->next;
 }
if (i==0) printf("\nLitakiv namae");
 getch();
 Menu(f);
}

void color(char *str,int n)
{

int i=0;
textcolor(n);
  while (i<strlen(str))
    {
     putch(str[i]);
     i++;
    }
}

void Punkt(int p,int x1,int y1)
{
 switch (p)
  {
   case 0:
     {
      gotoxy(x1+1,y1+1); color("1) Vyvesty spisok",9);
      gotoxy(x1+1,y1+5); color("2) Dodaty zapys",14);
      gotoxy(x1+1,y1+9); color("3) Third punkt",14);
      gotoxy(x1+1,y1+13); color("4) Fourth punkt",14);
      gotoxy(x1+1,y1+17); color("5) Exit     ",14);
     } break;
   case 1:
     {
      gotoxy(x1+1,y1+1); color("     1) Vyvesty spisok",9);
      gotoxy(x1+1,y1+5); color("2) Dodaty zapys     ",14);
      gotoxy(x1+1,y1+9); color("3) Third punkt     ",14);
      gotoxy(x1+1,y1+13); color("4) Fourth punkt     ",14);
      gotoxy(x1+1,y1+17); color("5) Exit     ",14);
     } break;
   case 2:
     {
      gotoxy(x1+1,y1+1); color("1) Vyvesty spysok     ",14);
      gotoxy(x1+1,y1+5); color("     2) Dodaty zapys",9);
      gotoxy(x1+1,y1+9); color("3) Third punkt     ",14);
      gotoxy(x1+1,y1+13); color("4) Fourth punkt     ",14);
      gotoxy(x1+1,y1+17); color("5) Exit     ",14);
     } break;
   case 3:
     {
      gotoxy(x1+1,y1+1); color("1) Vyvesty spysok     ",14);
      gotoxy(x1+1,y1+5); color("2) Dodaty zapys     ",14);
      gotoxy(x1+1,y1+9); color("     3) Third punkt",9);
      gotoxy(x1+1,y1+13); color("4) Fourth punkt     ",14);
      gotoxy(x1+1,y1+17); color("5) Exit     ",14);
     } break;
   case 4:
     {
      gotoxy(x1+1,y1+1); color("1) Vyvesty spysok     ",14);
      gotoxy(x1+1,y1+5); color("2) Dodaty zapys     ",14);
      gotoxy(x1+1,y1+9); color("3) Third punkt     ",14);
      gotoxy(x1+1,y1+13); color("     4) Fourth punkt",9);
      gotoxy(x1+1,y1+17); color("5) Exit     ",14);
     } break;
   case 5:
     {
      gotoxy(x1+1,y1+1); color("1) Vyvesty spysok     ",14);
      gotoxy(x1+1,y1+5); color("2) Dodaty zapys     ",14);
      gotoxy(x1+1,y1+9); color("3) Third punkt     ",14);
      gotoxy(x1+1,y1+13); color("4) Fourth punkt     ",14);
      gotoxy(x1+1,y1+17); color("     5) Exit",9);
     } break;
  }
}

*/