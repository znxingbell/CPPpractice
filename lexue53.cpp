#include <stdio.h>  
 
int main()  
{  
// 输入n（n<100)个整数，按照指定的方式（升序或降序）进行排序  
    int n, flag, a[100];  
    scanf("%d%d", &n, &flag);  
    input(a, n);  
    sort(a, n, flag); // flag=0：升序，flag=1：降序  
    output(a, n);  
    return 0;  
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
};    
void sort(int *p, int n, int flag){
    for(int i=0; i<n; i++)  
        for(int j=i+1; j<n; j++)  
            if( (flag==0 && p[i]>p[j]) || (flag==1 && p[i]<p[j]) )  
                swap(p+i, p+j);  
    return;
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