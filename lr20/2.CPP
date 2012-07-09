#include <stdio.h>
  #include <stdlib.h>
     struct st {
        int n;
        st *sp;
    } *first=NULL,*last,*q;
void Add (int N) {
  q=(st*)malloc(sizeof(st));
   if (first==NULL) first=q;
                            
      else last->sp=q;	
                        
        q->n=N;		
                        
      last=q; 		
    last->sp=NULL;
 }
  int View()		
                        
   { return first->n; }	
void Delete()
 {
  if (first==last) q=NULL;	   

     else q=first->sp;		   
                                   
      free(first);		  
  first=q;
   }
    
   void main() {
      int i,k=1;
    do  {
       scanf("%d",&k);		     
      if (k!=0) Add(k);		     
                                     
    } while (k!=0);		     

while (first!=NULL)  {		//Доки список не пустий
     k=View();			        //робимо k рівним першому
                                                    // елементу в списку
   if (k%2==0) printf("%d ",k);	//якщо елемент парний 
                                                     //виводимо його на екран
    Delete();			//Видаляємо перший елемент
    }
 }

   


