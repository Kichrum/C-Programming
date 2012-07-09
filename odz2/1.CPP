#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{clrscr();
randomize();
const int n=5;

int a[n], d[n], b[2*n], i;

for(i=0;i<n;i++) {
  a[i]=random(100);
  d[i]=random(100);
 }

printf("Yakscho vektory:\nA=(");
for(i=0;i<n-1;i++) printf("%d;",a[i]);
printf("%d)\nD=(",a[n-1]);
for(i=0;i<n-1;i++) printf("%d;",d[i]);
printf("%d)\n\nTodi B=(",d[n-1]);


for(i=0;i<2*n;i++)
 {
  if(i%2==0) b[i]=a[i/2];
  else b[i]=d[i/2];
 }

for(i=0;i<2*n-1;i++) printf("%d;",b[i]);
printf("%d)",b[2*n-1]);


getch();}
