#include <stdio.h>  
#include <math.h>  
int main()  
{  
    int n, m;  
    int isPrime( int );  // 若是素数函数isPrim返回1，否则返回0   
      
    scanf("%d%d", &n, &m);  
    while ( n < m-1 )  
    {  
        if ( isPrime(n) && isPrime(n+2) )  
        {  
            printf("%d,%d\n", n, n+2);  
        }  
        n++;  
    }  
    return 0;  
}  

int isPrime(int x) 
{  
    int i;  
    if ( x == 1 )  
    {  
        return 0;  
    }  
    for ( i = 2; i <= sqrt(x); i++ )  
    {  
        if ( x % i == 0 )  
        {  
            return 0;  
        }  
    }  
    return 1;
}  
 