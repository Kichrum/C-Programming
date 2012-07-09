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

LIST *first=NULL,*last;
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
 Window(5,3,74,23,7,1,"Noviy zapys");

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

 cprintf("Artykul:\n\r\n\r\n\rNazva: \n\rKil'kist':\n\rVartist':\n\r");
 gotoxy(10,1); cprintf("[C] Choloviche");
 gotoxy(10,2); cprintf("[D] Dams'ke");
 gotoxy(10,3); cprintf("[P] Dyt'ache");
 gotoxy(11,1); CDP(q->db.art,1);




 gotoxy(1,4);
//  scanf("%s",&q->db.art);
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

char* artykul(char x[2])
{
 if(strcmp(x,"D")==0) return "Dams\'ke";
 if(strcmp(x,"C")==0) return "Choloviche";
 if(strcmp(x,"P")==0) return "Dytyache";
 else return x;
}


void vyved(void)
{
 textmode(LASTMODE);
 clrscr();

 Window(5,3,74,23,7,1,"Baza danyh");

 LIST *q=first;

  int i=1,max=15;

  cprintf("| No.|  Artykul  |        Nazva        | Kil'kist' |   Vartist'   |\n\r");

  cprintf("%c----|-----------|---------------------|-----------|--------------%c\n\r",195,180);
  while (q!=NULL)
   {
	cprintf("|%3d | %10s| %20s| %9d | %8.2f UAH |\n\r",i,artykul(q->db.art),q->db.name,q->db.kil,q->db.vart);
	if(i%max==0 && q->next!=NULL)
	 {
	  cputs("\n\r                    Ne vmischaetsya! Press ENTER.");
	  getch();
	  clrscr();
	  cprintf("| No.|  Artykul  |        Nazva        | Kil'kist' |   Vartist'   |\n\r");
	  cprintf("%c----|-----------|---------------------|-----------|--------------%c\n\r",195,180);
	 }
	q=q->next;
	i++;

   }
   cprintf("%c-----------------------------------------------------------------%c\n\r",192,217);
   cprintf("       Dlya povernennya v Menue natysnit' bud'-yaku klavishu...");
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
// cprintf("(D = Dams'ke, C = Choloviche abo P = Dytyache):\n\r");
// gotoxy(28,10);
// scanf("%s",&x);
// CDP(x);
 clrscr();
 LIST *q=first;
  cprintf("| No.|        Nazva        | Kil'kist' |   Vartist'   |\n\r");
  cprintf("%c----|---------------------|-----------|--------------%c\n\r",195,180);
  while (q!=NULL)
   {
    if(strcmp(x,q->db.art)==0)
     {
      cprintf("|%3d | %20s| %9d | %8.2f UAH |\n\r",i,q->db.name,q->db.kil,q->db.vart);

	 if(j%max==0 && q->next!=NULL)
	 {
	  cputs("\n\r               Ne vmischaetsya! Press ENTER.");
	  getch();
	  clrscr();
	  cprintf("| No.|        Nazva        | Kil'kist' |   Vartist'   |\n\r");
	  cprintf("%c----|---------------------|-----------|--------------%c\n\r",195,180);
	 }

      j++;
     }
    q=q->next;
    i++;

   }
  cprintf("%c-----------------------------------------------------%c\n\r",192,217);

  cprintf("Dlya povernennya v Menue natysnit' bud'-yaku klavishu...");

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
  cprintf("| No.|        Nazva        | Kil'kist' |\n\r");
  cprintf("%c----|---------------------|-----------%c\n\r",195,180);

  while (q!=NULL)
   {
    if(strcmp("D",q->db.art)==0)
     {
      cprintf("|%3d | %20s| %9d |\n\r",i,q->db.name,q->db.kil);
      if(j%max==0 && q->next!=NULL)
	 {
	  cputs("\n\r      Ne vmischaetsya! Press ENTER.");
	  getch();
	  clrscr();
	  cprintf("| No.|        Nazva        | Kil'kist' |\n\r");
	  cprintf("%c----|---------------------|-----------%c\n\r",195,180);
	 }


      j++;
     }
    q=q->next;
    i++;

   }

   cprintf("%c--------------------------------------%c\n\r",192,217);
  cprintf("       Dlya povernennya v Menue\n\r     natysnit' bud'-yaku klavishu...");

  getch();
  menue();


}


int cursor(int&n)
{
 _setcursortype(1);
 int key,x,y;
 int winw,winh;
 struct text_info win;
 gettextinfo(&win);
// winw=win.winright-win.winleft+1;
// winh=win.winbottom-win.wintop+1;
 x=win.curx;y=win.cury;
 gotoxy(0,0);
// key=getch();
 do
 {
  key=getch();
  if(key==0x1b) {n=5;return n;}
   else if (key!=0) n=5;

  switch(key)
  {
   case 80: if (y<7) y++; break;
   case 72: if (y>3) y--; break;
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
 }while(key!=13);

 return n;

}

void CDP(char*c,int ymin)
{
 _setcursortype(1);
 int key,x,y,n;
// int winw,winh;
 struct text_info win;
 gettextinfo(&win);
// winw=win.winright-win.winleft+1;
// winh=win.winbottom-win.wintop+1;
 x=win.curx;y=win.cury;
 gotoxy(0,0);
// key=getch();
 do
 {
  key=getch();

  switch(key)
  {
   case 80: if (y<ymin+2) y++; break;
   case 72: if (y>ymin) y--; break;
   case 13: {
	     if(y==ymin) n=1;
	     if(y==ymin+1) n=2;
	     if(y==ymin+2) n=3;
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
 Window(22,7,56,16,7,1,"Menue");
// gotoxy(0,0);
 _setcursortype(1);
 cprintf("      Oberit' potribnu diyu:\n\r\n\r");

 cprintf("[1] Poshuk po artykulu\n\r[2] Asortiment dams'kogo vzuttya\n\r");
 cprintf("[3] Vyvesty bazu danyh\n\r[4] Dodaty element\n\r");
 cprintf("[5] Viyty");
// scanf("\t%d",&n);
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
// getch();
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
   getch();
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