#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 10
void main()
{
 clrscr();

 FILE *mas;
 mas=fopen("mas.dan","wb");
 float a[10],k,s,rez;
 int i,n;

 for(i=0;i<N;i++)
 {
  scanf("%f",&k);
  fwrite(&k,sizeof(float),1,mas);
 }
 fclose(mas);

 mas=fopen("mas.dan","rb+");
 n=fread(a,sizeof(float),N,mas);
 for(i=0,k=0,s=0;i<n;i++)
 {
  printf("%f\n",a[i]);
  if(a[i]>0) {k+=a[i]; s++;}
 }
 if (s!=0)
 {
  rez=k/s;
  printf("\n%f",k/s);
  fwrite(&rez,sizeof(float),1,mas);
 }
 else puts("ERROR!");



 fclose(mas);


 getch();

}