#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float delta,a,x;
 char variant;
 printf("a=");
 scanf("%f",&a);
 printf("x=");
 scanf("%f",&x);
 printf("Vvedite variant ('a','b',ili 'c'):");
 fflush(stdin); //Dlya %c ili %s OBYAZATEL'NO!
 scanf("%c",&variant);


 switch (variant)
 {
 case 'A':case 'a':
	 {
	  if(x>0)
	  {delta=pow(tan(a*x),1.0/3.0)/log(x);
	  printf("a) %f\n",delta);}
	  else puts("ERROR! Only for x>0");
	 }
 break;
 case 'B':case 'b':{
	  if (tan(a*x)!=0) {
	  delta=log(x)/sqrt(tan(a*x));
	  printf("b) %f\n",delta);}
	  else puts("ERROR! */0");
	 }
 break;
 case 'C':case 'c':{
	  if(tan(a*x)!=0) {
	  delta=(log(x)+log10(x))/tan(a*x);
	  printf("c) %f\n",delta);}
	  else puts("ERROR! */0");
	 }
 break;
 default: puts("Net resheniy\n");
 }
 getch();
}
