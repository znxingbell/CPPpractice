#include "stdio.h"  
#include "stdlib.h"  
  
struct node  
{   int  data;  
    struct node * next;  
} ;  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
  
void outlist( PNODE );  
int ins_list( PNODE, int );  
   
int main ( )  
{   int num=1;  
    PNODE head;  
  
    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   scanf("%d", &num);  
        if ( num!=0 )  
            ins_list( head, num);  
    }  
  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   printf("%d\n", p->data);  
        p = p->next;  
    }  
}  
  

int ins_list( PNODE h, int num ){ 
    PNODE new_node = (PNODE)malloc(sizeof(NODE));
    new_node->data = num;
    new_node->next = NULL;
    while(h->next != NULL){
        h = h->next;
    }
    h->next = new_node;
    return 0;
} 
