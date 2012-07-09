#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 7
void main()
{
 clrscr();

 FILE *mas;

 float a[N],k;
 int i,n,f;
/*
 mas=fopen("mas.dan","wb");
 for(i=0;i<N;i++)
 {
  scanf("%f",&k);
  fwrite(&k,sizeof(float),1,mas);
 }
 fclose(mas);
//*/
 mas=fopen("mas.dan","rb+");
 n=fread(a,sizeof(float),N,mas);
 for(i=0,k=1,f=0;i<n;i++)
  if(a[i]<10) { k*=a[i]; f=1;}

 if(f==1){
  printf("\nResult: %f",k);
  fwrite(&k,sizeof(float),1,mas);
  }
  else puts("\nNemae menshe 10");




 fclose(mas);
//*/

 getch();

}