#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
int isPrim(int x)  
{   int i;  
    if ( x==2 ) return 1;       // 是素数，返回1  
    if ( x<=1 || x%2==0 )    return 0;   // 不是素数，返回0   
    for ( i=3; i<=sqrt(x); i+=2 )  
        if ( x%i==0 )   return 0;   // 不是素数，返回0   
    return 1;           // 是素数，返回1   
}  

int * input(int n) // 输入n个整数保存在动态申请的空间中  
{ 
    int *p = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++)  
        scanf("%d", p+i);
    return p;
} 
 
int PrimCount( int *p, int n)  // 统计n个整数中的素数数量  
{ 
    int count=0;
    for(int i=0; i<n; i++)  
        if(isPrim(p[i]))  
            count++;
    return count;
} 
  
int main()  
{   int n, count, *p;  
  
    scanf("%d", &n);        // 接受整数数量n  
    p = input( n );         // 调用函数输入n个整数   
    count = PrimCount( p, n );  // 对素数进行计数   
    printf("PrimCount=%d\n", count);  
    return 0;  
}  