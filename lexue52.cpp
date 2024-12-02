#include <stdio.h>  
  
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
};  
int input(int *p, int n){
    for(int i=0; i<n; i++)  
        scanf("%d", p+i);
    return 0;
};  
int output(int *p, int n){
    for(int i=0; i<n; i++)  
        printf("%d,", *(p+i));  
    printf("\n");  
    return 0;
};  
int main()  
{  
// 分别将输入2*n（n<100)个整数保存在两个数组中，比较对应  
// 数组元素，将较小值保存在a数组中，较大值存入数组b中   
    int n, k, a[100], b[100];  
    scanf("%d", &n);  
    input(a, n);  
    input(b, n);  
    for ( k=0; k<n; k++ )  
    {   if( a[k] > b[k] )   
            swap(&a[k], &b[k]);   
    }  
    output(a, n);  
    output(b, n);   
    return 0;  
}  