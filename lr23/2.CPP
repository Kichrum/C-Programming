#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
 clrscr();

 FILE *vhod,*rez;
 vhod=fopen("vhodn.dan","rt");
 rez=fopen("rez.dan","wt");
 float z,x;
 int i=0,max=10;



 if(vhod==NULL)
  {printf("Pusto!"); getch(); exit(0);}

 while(!feof(vhod))
 {
   fscanf(vhod,"%f",&x);
   z=exp(3*x)+cos(x);
  if(i<max) {
   printf("z(%f)\t=\t%1.1f\n",x,z);

   }
   else {
	 puts("Ne vmischaetsya! Natysnit' any key.");
	 i=0;
	 getch();
	 clrscr();
	 printf("z(%f)\t=\t%1.1f\n",x,z);
	}
   fprintf(rez,"%1.1f\t%1.1f\n",x,z);
   i++;
 }
 fclose(vhod);
 fclose(rez);


 getch();

}