#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float x,z;
 int n;
 printf("x="); scanf("%f",&x);
 printf("Vvedite 2, 5 ili 7:\n 2) z=sin(x+5);\n 5) z=log(x);\n 7) z=1/cos(x^3);\nn="); scanf("%d",&n);

 switch (n)
 {
  case 2: {
	   z=sin(x+5);
	   printf("%d) z=%f\n",n,z);
	  }
  break;
  case 5: {
	   z=log10(x);
	   printf("%d) z=%f\n",n,z);
	  }
  break;
  case 7: {
	   z=1/cos(pow(x,3));
	   printf("%d) z=%f\n",n,z);
	  }
  break;
  default: puts("ERROR!");
 }

 getch();
}