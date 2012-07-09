#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a[10][15],b[15][12],i,j;
FILE *f;


void dob1(int c[10][15])
{
int d=1;

for(i=0;i<10;i++)
 {
 for(j=0;j<15;j++)
  if(c[i][j]<0) d*=c[i][j];
 fprintf(f,"%d ",d);
 d=1;
 }
}

void dob2(int c[15][12])
{
int d=1;

for(i=0;i<15;i++)
 {
 for(j=0;j<12;j++)
  if(c[i][j]<0) d*=c[i][j];
 fprintf(f,"%d ",d);
 d=1;
 }
}


void main()
{
 clrscr();
 randomize();

 f=fopen("rez.txt","w");

 fprintf(f,"A=\n");
 for(i=0;i<10;i++) {
  for(j=0;j<15;j++)
  {a[i][j]=random(18)-9;
   fprintf(f," %d",a[i][j]);}
  fprintf(f,"\n");}

 fprintf(f,"\nB=\n");

 for(i=0;i<15;i++) {
  for(j=0;j<12;j++)
   {b[i][j]=random(18)-9; fprintf(f," %d",b[i][j]);}
   fprintf(f,"\n");}

fprintf(f,"\nDlya A:\n");
dob1(a);
fprintf(f,"\nDlya B:\n");
dob2(b);
fclose(f);

printf("RESULT COMPILED!\nSaved to file \"REZ.TXT\"");



 getch();
}