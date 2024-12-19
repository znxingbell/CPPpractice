#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct sdata  
{  int num;  
   struct sdata *next;  
} ;  
typedef struct sdata SNODE;  
void movenode( SNODE * head, int m){
    SNODE *p = head;
    for(int i=1;i<m;i++){
        if(p->next == NULL)
            return;
        p = p->next;
    }
    SNODE *q = p->next;
    p->next = p->next->next;
    q->next = head->next;
    head->next = q;
    return;
}  
  
void setlink( SNODE * head, int n )  
{     
    SNODE *p;  
  
    while ( n > 0 )  
    {   p = ( SNODE * ) malloc( sizeof( SNODE ) );  
        p->num = n;  
        p->next = head->next;  
        head->next = p;  
        n --;  
    }  
}  
  
void outlink( SNODE * head )  
{  
    while( head->next != NULL )  
    {  
        head = head->next;  
        printf( "%d,", head->num );  
    }  
    return;  
}  
  
int main( )  
{   int n, m;  
    SNODE * head = NULL;  
  
    scanf("%d%d", &n, &m );  
    head = ( SNODE * ) malloc( sizeof( SNODE ) );  
    head->num = -1;  
    head->next = NULL;  
    setlink( head, n );  
  
    movenode( head, m );   /* This is waiting for you. */  
  
    outlink( head );  
    printf("\n");  
    return 0;  
} 