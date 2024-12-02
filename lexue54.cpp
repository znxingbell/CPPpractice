#include <stdio.h>  
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
};    
void sort(int *p, int n, int (*f)(int a, int b)){
        for(int i=0; i<n; i++)  
        for(int j=i+1; j<n; j++)  
            if(f(p[i], p[j])==-1)  
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
int up(int a, int b){
    if(a<b) return 1;
    else if(a==b) return 0;
    else return -1;
};       // a<b:1； a=b:0；a>b:-1反序   
int down(int a, int b){
    if(a<b) return -1;
    else if(a==b) return 0;
    else return 1;
};     // a<b:-1；a=b:0；a>b:1 正序   
  
int main()  
{  
    int n, flag, a[100];  
    scanf("%d%d", &n, &flag);   // n：数组元素数量； flag=0：升序，flag=1：降序   
    input(a, n);  
    if ( flag==0 )  
        sort(a, n, up);     // 0：升序，1：降序  
    else   
        sort(a, n, down);  
    output(a, n);  
    return 0;  
}  