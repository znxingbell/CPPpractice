#include <stdio.h>  
  
typedef struct buy  
{  char  gname;  
   int   sname;  
   int   gprice;  
} BUY;  
  
int main( )  
{  int i, j, n;  
   int min, price[10][3];  
   int findm( int n, int price[][3], BUY scheme[] );  
  
   static BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };  
  
   scanf( "%d", &n );  
   for( i = 0; i < n; i++ )  
    for( j = 0; j < 3; j++ )  
       scanf( "%d", &price[i][j] );  
  
   min = findm( n, price, scheme );  
  
   printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );  
   for ( i=0; i < 3; i++ )  
       printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice );  
   return 0;  
}  
  
int findm( int n, int gp[ ][3], BUY schm[ ] ){
   int flag[10] = {0};
   for(int j = 0; j < 3; j++ )
      schm[j].gprice = 1000;
   for(int j = 0; j < 3; j++ ){
      for(int i = 0; i < n; i++ ){    
         if(gp[i][j] < schm[j].gprice && flag[i] == 0 ){
            schm[j].gprice = gp[i][j];
            schm[j].sname = i + 1;
         }
      }
      flag[schm[j].sname-1] = 1;
   }
   return schm[0].gprice + schm[1].gprice + schm[2].gprice;                             
}                                              
  