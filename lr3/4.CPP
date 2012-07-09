#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
 clrscr();

 float delta,a,x;
 int n;
 puts("a=");
 scanf("%f",&a);
 puts("x=");
 scanf("%f",&x);
 puts("n=");
 scanf("%d",&n);


 switch (n)
 {
 case 10:{
	  delta=pow(tan(a*x),1.0/3.0)/log(x);
	  printf("10) %f\n",delta);
	 }
 break;
 case 15:{delta=log(x)/sqrt(tan(a*x));
	  printf("15) %f\n",delta);
	 }
 break;
 case 20:{delta=(log(x)+log10(x))/tan(a*x);
	  printf("20) %f\n",delta);
	 }
 break;
 default: puts("Net resheniy\n");
 }
 getch();
}
