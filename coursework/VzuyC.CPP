#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define Esc 0*1b

typedef struct aeroflot
{
int n;
char misto[20];
char chas_v[10];
char chas_p[10];
int k;
} aer;


typedef struct list
{
int n;
aer zapis;
struct list *next;
} lel;

lel *first=NULL,*last;

lel* CreateList(FILE *f);
void PrintList(FILE *f);
void AddRecord(FILE *f);
void DeleteList();
int  Menu(FILE *f);
void FirstYmova(FILE *f);
void SecondYmova(FILE *f);
void color(char *str,int n);
void Punkt(int p,int x1,int y1);
void Ramka(int x,int y,int x1,int y1,int x2,int y2);

void main()
{
clrscr();
textcolor(14);
textbackground(0);
char *fname="krsinput.txt";

FILE *f;

f=fopen(fname,"r+");
if (f==NULL) {printf("\nFile not open!");getch();exit(1);}

while (!feof(f))
  CreateList(f);

Menu(f);

DeleteList();
fclose(f);

}

lel* CreateList(FILE *f)
{
lel *q;

q=(lel*)malloc(sizeof(lel));
if (q==NULL) {printf("NETY PAM9TI");getch();exit(1);}

if (first==NULL) {first=q;first->next=NULL;}
  else {last->next=q;q->next=NULL;}

fscanf(f,"%d%s%s%s%d",&q->zapis.n,&q->zapis.misto,&q->zapis.chas_v,&q->zapis.chas_p,&q->zapis.k);

last=q;
return last;
}


void PrintList(FILE *f)
{
clrscr();
lel *q=first;


printf("N      Misto    Chas vidlioty  Chas pribytt9  K-st mistc\n");
for(int i=0;i<55;i++)
 printf("_");
while (q!=NULL)
  {
   puts("");
   printf("\n%d%12s%12s%15s%13d",q->zapis.n,q->zapis.misto,q->zapis.chas_v,q->zapis.chas_p,q->zapis.k);
   q=q->next;
  }
  getch();
  Menu(f);
}

void DeleteList()
{
lel *p;
while (first!=last)
 {
  p=first;
  first=first->next;
  free(p);
 }
free(first);
}

void AddRecord(FILE *f)
{
clrscr();
lel *q;

q=(lel*)malloc(sizeof(lel));
if (first==NULL) {first=q;first->next=NULL;}
  else {last->next=q;q->next=NULL;last=q;}

printf("\nNomer reisa:");
scanf("%d",&q->zapis.n);
fprintf(f,"\n%d\n",q->zapis.n);

printf("\nMisto:");
scanf("%s",&q->zapis.misto);
fprintf(f,"%s\n",q->zapis.misto);

printf("\nChas vidlioty:");
scanf("%s",&q->zapis.chas_v);
fprintf(f,"%s\n",q->zapis.chas_v);

printf("\nChas pribytt9:");
scanf("%s",&q->zapis.chas_p);
fprintf(f,"%s\n",q->zapis.chas_p);

printf("\nK-st` vilnix mistc:");
scanf("%d",&q->zapis.k);
fprintf(f,"%d",q->zapis.k);

printf("\nDodano");
getch();
Menu(f);
}

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
lel *q=first;
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
lel *q=first;
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
