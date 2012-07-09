#include <conio.h> 
#include <stdlib.h> 
#include <stdio.h> 
void main()
{
int *p[10], i, j;
clrscr();
randomize();
for (i=0;i<10;i++)
p[i] = (int*) malloc (15 * sizeof (int));
for (i = 0; i < 10; i++)
for (j = 0; j < 15; j++ )
{
*(p[i] + j ) = random(5);
printf("%3d", *(p[i] + j ));
if ( (j + 1)%20 == 0 )
printf ("\n" ) ;
}
for ( i=0; i<10; i++ )
free( p[i] );
}