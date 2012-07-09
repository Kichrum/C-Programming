#include <stdio.h>
#include <math.h>
#include <conio.h>

void main()
{
 float k=1,k1=0;
 int n,p,K=0;
 clrscr();
 printf("n=");
 scanf("%d",&n);
 do
  {
   k=k1+k;
   k1=k-k1;
   p=int(k/pow(10,n-1));

   if ((k<pow(10,n)) && (k>=pow(10,n-1)) && (p%2==0)) K++;
  }
 while (k<pow(10,n));
 printf("Kil'kist' %d-znachnyh chisel Fibonacci, u yakyh starsha tsifra parna, = %d",n,K);
 getch();
}