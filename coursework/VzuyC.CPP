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
	} DB;

typedef struct list
	{
	 DB db;
	 struct list *next;
	} LIST;

LIST *first=NULL,*last=NULL;
FILE *f;

int menue(void);


void Window(int x1, int y1, int x2, int y2, int wcol, int wbk, char* title)
{
 int x,y;
 window (1, 1, 80, 25);
 textcolor (wcol) ;
 textbackground (wbk);
 gotoxy (x1, y1);
 putch(201);
 for  (x=x1+1; x<x2; x++)
  putch(205);
 putch(187);
 for  (y=y1+1; y<y2; y++)
    {
	gotoxy (x1, y) ;
	putch(186);
	gotoxy (x2, y);
	putch(186);
    }
 gotoxy(x1, y2) ;
 putch(200);
 for (x=x1+1; x<x2; x++)
  putch(205);
 putch(188);
 if  (*title!=0)   {
	x=(x2-x1+1-(strlen(title)+2))/2;
	if  (x>1)
	{
	gotoxy(x1+x+1, y1);
	putch(181);
	cputs (title);
	putch(198);
	}
	}
 window (x1+1, y1+1, x2-1, y2-1);
 clrscr();
 _setcursortype(0);
}



void CDP(char*,int);
void vved(void)
{
 textmode(LASTMODE);
 clrscr();
 Window(25,8,54,15,7,1,"Noviy zapys");

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

 cprintf("Artykul:\n\r\n\r\n\rNazva: \n\rKil'kist':\n\rVartist':");
 gotoxy(10,1); cprintf("[C] Choloviche");
 gotoxy(10,2); cprintf("[D] Dams'ke");
 gotoxy(10,3); cprintf("[P] Dyt'ache");
 gotoxy(11,1); CDP(q->db.art,1);




 gotoxy(1,4);
  fprintf(f,"%s ",q->db.art);

 cprintf("Nazva: ");
  scanf("%s",&q->db.name);
  fprintf(f,"%s ",q->db.name);

 cprintf("\rKil'kist': ");
  scanf("%d",&q->db.kil);
  fprintf(f,"%d ",q->db.kil);

 cprintf("\rVartist': ");
  scanf("%f",&q->db.vart);
  fprintf(f,"%f",q->db.vart);

  if(k!=0) menue();

}



int readfile(void)
{
 LIST *q=(LIST*)malloc(sizeof(LIST));

 if (q==NULL)
  {
   printf("Fatal ERROR: Ne dostatn'o pamyati!\n");
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

char* artykul(char x[2])
{
 if(strcmp(x,"D")==0) return "Dams'ke";
 if(strcmp(x,"C")==0) return "Choloviche";
 if(strcmp(x,"P")==0) return "Dyt'ache";
 else return x;
}


void vyved(void)
{
 textmode(LASTMODE);
 clrscr();

 Window(5,3,74,23,7,1,"Baza danyh");

 LIST *q=first;

  int i=1,max=15;

  cprintf("³ No.³  Artykul  ³        Nazva        ³ Kil'kist' ³   Vartist'   ³\n\r");
  cprintf("ÃÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n\r");
  while (q!=NULL)
   {
	cprintf("³%3d ³ %10s³ %20s³ %9d ³ %8.2f UAH ³\n\r",i,artykul(q->db.art),q->db.name,q->db.kil,q->db.vart);
	if(i%max==0 && q->next!=NULL)
	 {
	  cprintf("\n\r             Ne vmischaetsya! Natysnit' ENTER.");
	  getch();
	  clrscr();
	  cprintf("³ No.³  Artykul  ³        Nazva        ³ Kil'kist' ³   Vartist'   ³\n\r");
	  cprintf("ÃÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n\r");
	 }
	q=q->next;
	i++;

   }
   cprintf("ÀÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\r");
   cprintf("              Dlya povernennya v Menu natysnit' ENTER.");
  getch();
  menue();
}


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
 textmode(LASTMODE);
 clrscr();

 Window(11,3,68,23,7,1,"Poshuk po artykulu");

 char x[2];
 int i=1,j=1,max=14;
 gotoxy(20,8); cprintf("Poshukoviy artykul");
 gotoxy(22,9); cprintf("[C] Choloviche");
 gotoxy(22,10); cprintf("[D] Dams'ke");
 gotoxy(22,11); cprintf("[P] Dyt'ache");
 gotoxy(23,9); CDP(x,9);
 _setcursortype(0);
 clrscr();
 LIST *q=first;
  cprintf("³ No.³        Nazva        ³ Kil'kist' ³   Vartist'   ³\n\r");
  cprintf("ÃÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n\r");
  while (q!=NULL)
   {
    if(strcmp(x,q->db.art)==0)
     {
      cprintf("³%3d ³ %20s³ %9d ³ %8.2f UAH ³\n\r",i,q->db.name,q->db.kil,q->db.vart);

	 if(j%max==0 && q->next!=NULL)
	 {
	  cputs("\n\r            Ne vmischaetsya! Natysnit' ENTER.");
	  getch();
	  clrscr();
	  cprintf("³ No.³        Nazva        ³ Kil'kist' ³   Vartist'   ³\n\r");
	  cprintf("ÃÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n\r");	 }

      j++;
     }
    q=q->next;
    i++;

   }
  cprintf("ÀÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n\r");

  cprintf("       Dlya povernennya v Menu natysnit' ENTER.");

  getch();
  menue();
}

void sdam(void)
{
 textmode(LASTMODE);
 clrscr();

 Window(18,3,60,23,7,1,"Asortyment dams'kogo vzuttya");
 int i=1,j=1,max=14;
 LIST *q=first;
  cprintf("³ No.³        Nazva        ³ Kil'kist' ³\n\r");
  cprintf("ÃÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n\r");

  while (q!=NULL)
   {
    if(strcmp("D",q->db.art)==0)
     {
      cprintf("³%3d ³ %20s³ %9d ³\n\r",i,q->db.name,q->db.kil);
      if(j%max==0 && q->next!=NULL)
	 {
	  cputs("\n\r    Ne vmischaetsya! Natysnit' ENTER.");
	  getch();
	  clrscr();
	  cprintf("³ No.³        Nazva        ³ Kil'kist' ³\n\r");
	  cprintf("ÃÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n\r");
	 }


      j++;
     }
    q=q->next;
    i++;

   }

  cprintf("ÀÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÙ\n\r");
  cprintf("         Dlya povernennya v Menue\n\r          natysnit' ENTER.");

  getch();
  menue();


}


int cursor(int&n)
{
 _setcursortype(1);
 int key,x,y;
 struct text_info win;
 gettextinfo(&win);
 x=win.curx;y=win.cury;
 gotoxy(0,0);
 do
 {
  key=getch();
  if(key==0x1b) {n=5;return n;}
   else if (key!=0) n=5;

  switch(key)
  {
   case 80: if (y<7) y++; break;
   case 72: if (y>3) y--; break;
   case 49: n=1; break;
   case 50: n=2; break;
   case 51: n=3; break;
   case 52: n=4; break;
   case 53: n=5; break;
   case 13: {
	     if(y==3) n=1;
	     if(y==4) n=2;
	     if(y==5) n=3;
	     if(y==6) n=4;
	     if(y==7) n=5;
	     break;
	    }
   default: n=5;
  }
  gotoxy(x,y);
 }while(key!=13 && !(key>=49 && key<=53));

 return n;

}

void CDP(char*c,int ymin)
{
 _setcursortype(1);
 int key,x,y,n;
 struct text_info win;
 gettextinfo(&win);
 x=win.curx;y=win.cury;
 gotoxy(0,0);
 do
 {
  key=getch();

  switch(key)
  {
   case 80: if (y<ymin+2) y++; break;
   case 72: if (y>ymin) y--; break;
   case 13: {
	     if(y==ymin) {n=1; cprintf("%c",178);}
	     if(y==ymin+1) {n=2; cprintf("%c",178);}
	     if(y==ymin+2) {n=3; cprintf("%c",178);}
	     break;
	    }
   default: n=1;
  }
  gotoxy(x,y);
 }while(key!=13);

 switch(n)
 {
  case 1: sscanf("C","%s",c); break;
  case 2: sscanf("D","%s",c); break;
  case 3: sscanf("P","%s",c); break;
 }
}


int menue(void)
{
 textmode(LASTMODE);
 clrscr();
 int n=0;
 Window(22,8,56,16,7,1,"Menue");
 _setcursortype(1);
 cprintf("      Oberit' potribnu diyu:\n\r\n\r");

 cprintf("[1] Poshuk po artykulu\n\r[2] Asortiment dams'kogo vzuttya\n\r");
 cprintf("[3] Vyvesty bazu danyh\n\r[4] Dodaty element\n\r");
 cprintf("[5] Viyty");
 gotoxy(2,3);
 cursor(n);
 switch (n)
  {
   case 1: sart(); break;
   case 2: sdam(); break;
   case 3: vyved(); break;
   case 4: vved(); break;
   case 5: return 1; break;
  }
 return 0;
}

void welcome()
{
 textmode(LASTMODE);
 clrscr();
 Window(10,3,70,23,1,15,"Welcome!");
 textcolor(5);
  cprintf("K    K    i     CCC    H     H  RRRRR    U    U  M       M\n\r");
  cprintf("K   K         C     C  H     H  R    R   U    U  M M   M M\n\r");
  cprintf("K  K      I   C        H     H  R     R  U    U  M  M M  M\n\r");
  cprintf("K K       I   C        H     H  R    R   U    U  M   M   M\n\r");
  cprintf("K  K      I   C        H HHH H  R RR     U    U  M       M\n\r");
  cprintf("K   K     I   C        H     H  R    R   U    U  M       M\n\r");
  cprintf("K    K    I   C     C  H     H  R     R  U    U  M       M\n\r");
  cprintf("K     K   I     CCC    H     H  R     R   UUUU   M       M\n\r\n\r");
 textcolor(9);
  cprintf("   w  w  w  .  k  i  c  h  r  u  m  .  o  r  g  .  u  a\n\r\n\r");
 textcolor(1);
  cprintf("    Virogidno, Tse Vash pershiy zapusk progravmy dlya\n\r  stvorennya i keruvannya bazou danyh vzuttevogo magazynu\n\r                          \"Vzuy C\"!\n\r");
 textcolor(0);
  cprintf("Schob rozpochaty robotu z programou, neobhidno stvoryty\n\rbazu danyh. Natysnit' klavishu ENTER ta vvedit' sviy\n\rpershiy zapys u vashu bazu danyh.\n\r\"Vzuy C\" Stvoryt' fayl bazy ta pomistyt' yogo u sviy\n\rkatalog pid nazvou \"VZUYC.DB\".");
 getch();
 vved();
 clearlist();
}


int main(void)
{
 clrscr();
 float w; sscanf("1","%f",&w);

 if ((f=fopen("VZUYC.DB","r+"))==NULL)
  {
   fclose(f);
   if((f=fopen("VZUYC.DB","wt"))==NULL)
     {puts("Fatal ERROR: Ne stvoreno fayla!"); getch(); return 1;}
   welcome();
   fclose(f);
   f=fopen("VZUYC.DB","r+");
  }


 while (!feof(f))
    readfile();

 menue();

 clearlist();


 fclose(f);
 return 0;
}