#include <stdio.h>  
int main()   
{  
   int n, count( );  
   scanf("%d", &n);  
   printf("%d\n", count (n, n-1));    
   return 0;  
}  
    
int count( int n, int m )   
{ 
    if(n<1||m<1) return 0;
    if(n==1||m==1) return 1;
    if(n<m) return count(n, n);
    if(n==m) return 1+count(n, m-1);
    return count(n, m-1)+count(n-m, m);
}    
