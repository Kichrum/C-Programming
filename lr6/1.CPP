#include <stdio.h>
#include <conio.h>

void main()
{
 clrscr();


   int i, k;
     float mas[10],sa,s;
     k=0; s=0;
     puts("Vvedite elementy massiva:");
     for(i=0;i<10;i++)
     scanf("%f",&mas[i]);
     for(i=0;i<10;i++)
     if (mas[i]>0){ s+=mas[i]; k++;}
     sa=s/k;
printf("Seredne aryfmetychne %d dodatnih elementiv massyvu: %f\n",k,sa);





 getch();
}