#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
struct nn  
{  int no;     
   int num;     
};  
  
typedef struct nn DATA;  
  
int number( char * , DATA []);  
  
int main( )  
{     
   DATA b[100];    
   char sa[500];    
   int i, n;    
   gets( sa );   
   n = number( sa, b );   
   for ( i=0; i<n; i++ )   
       printf("%d %d\n", b[i].num, b[i].no );   
   return 0;  
}  

int cmp( const void *a, const void *b ){  
   return (*(DATA **)a)->num - (*(DATA **)b)->num;  
}

int number( char * str, DATA a[] ){
    int n = 0;
    char *token;
    token = strtok(str, " ");
    while (token != NULL) {
        sscanf(token, "%d", &a[n].num);
        n++;
        token = strtok(NULL, " ");
    }
    DATA **temp = (DATA **)malloc(n * sizeof(DATA));
    for (int i = 0; i < n; i++)
        temp[i] = &a[i];
    qsort(temp, n, sizeof(DATA *), cmp); 
    for(int i = 0; i < n; i++)
        temp[i]->no = i + 1;
    return n;
}
