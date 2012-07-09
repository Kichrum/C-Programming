#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


void tsvet(char *str,int n)
{

int i=0;
textcolor(n);
  while (i<strlen(str))
    {
     putch(str[i]);
     i++;
    }
}

void vydelenie(int p,int x1,int y1)
{
 switch (p)
  {
   case 0:
     {
      gotoxy(x1+1,y1+1); tsvet("1) Pervoe",4);
      gotoxy(x1+1,y1+5); tsvet("2) Vtoroe",2);
      gotoxy(x1+1,y1+9); tsvet("3) Tretee",2);
      gotoxy(x1+1,y1+13); tsvet("4) Chetvertoe",2);
      gotoxy(x1+1,y1+17); tsvet("5) Exit",2);
     } break;
   case 1:
     {
      gotoxy(x1+1,y1+1); tsvet("1) Pervoe",4);
      gotoxy(x1+1,y1+5); tsvet("2) Vtoroe",2);
      gotoxy(x1+1,y1+9); tsvet("3) Tretee",2);
      gotoxy(x1+1,y1+13); tsvet("4) Chetvertoe",2);
      gotoxy(x1+1,y1+17); tsvet("5) Exit",2);
     } break;
   case 2:
     {
      gotoxy(x1+1,y1+1); tsvet("1) Pervoe",2);
      gotoxy(x1+1,y1+5); tsvet("2) Vtoroe",4);
      gotoxy(x1+1,y1+9); tsvet("3) Tretee",2);
      gotoxy(x1+1,y1+13); tsvet("4) Chetvertoe",2);
      gotoxy(x1+1,y1+17); tsvet("5) Exit",2);
     } break;
   case 3:
     {
      gotoxy(x1+1,y1+1); tsvet("1) Pervoe",2);
      gotoxy(x1+1,y1+5); tsvet("2) Vtoroe",2);
      gotoxy(x1+1,y1+9); tsvet("3) Tretee",4);
      gotoxy(x1+1,y1+13); tsvet("4) Chetvertoe",2);
      gotoxy(x1+1,y1+17); tsvet("5) Exit",2);
     } break;
   case 4:
     {
      gotoxy(x1+1,y1+1); tsvet("1) Pervoe",2);
      gotoxy(x1+1,y1+5); tsvet("2) Vtoroe",2);
      gotoxy(x1+1,y1+9); tsvet("3) Tretee",2);
      gotoxy(x1+1,y1+13); tsvet("4) Chetvertoe",4);
      gotoxy(x1+1,y1+17); tsvet("5) Exit",2);
     } break;
   case 5:
     {
      gotoxy(x1+1,y1+1); tsvet("1) Pervoe",2);
      gotoxy(x1+1,y1+5); tsvet("2) Vtoroe",2);
      gotoxy(x1+1,y1+9); tsvet("3) Tretee",2);
      gotoxy(x1+1,y1+13); tsvet("4) Chetvertoe",2);
      gotoxy(x1+1,y1+17); tsvet("5) Exit",4);
     } break;
  }
}


void table(int x,int y,int x1,int y1,int x2,int y2)
{
clrscr();

window(1,1,80,25);

textcolor(2);
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


int menue(void)
{
int x1=3,x2=60,y1=3,y2=23;
int x,y;
table(x,y,x1,y1,x2,y2);
vydelenie(0,x1+1,y1+1);

x=x1+2;y=y1+2;
gotoxy(x,y);
char c=0;
int v=0;

while (v==0)
 {
 c=getch();
 if (c==27) {return 0;}

  switch (c)
    {
     case 80:
	if (y<y2-4)
	{
	gotoxy(x,y+=4);
	if (y==y1+2)  vydelenie(1,x1+1,y1+1);
	if (y==y1+6)  vydelenie(2,x1+1,y1+1);
	if (y==y1+10) vydelenie(3,x1+1,y1+1);
	if (y==y1+14) vydelenie(4,x1+1,y1+1);
	if (y==y1+18) vydelenie(5,x1+1,y1+1);
	gotoxy(x,y);
	}break;

     case 72:
	 if (y-4>y1)
	 {
	 gotoxy(x,y-=4);
	 if (y==y1+2)  vydelenie(1,x1+1,y1+1);
	 if (y==y1+6)  vydelenie(2,x1+1,y1+1);
	 if (y==y1+10) vydelenie(3,x1+1,y1+1);
	 if (y==y1+14) vydelenie(4,x1+1,y1+1);
	 if (y==y1+18) vydelenie(5,x1+1,y1+1);
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
    case 1: puts("\t\t...1..."); break;

     case 2: puts("\t\t...2..."); break;

     case 3: puts("\t\t...3..."); break;

     case 4: puts("\t\t...4...");break;

     case 5: return 0;break;

  }
getch();
return 1;
}



void main()
{
int k=1;
clrscr();
textcolor(2);
textbackground(0);
while (k!=0)
 k=menue();



}




