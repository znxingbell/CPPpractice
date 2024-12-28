#include <stdio.h>    
#include <stdlib.h>    
struct boy    
{   int num;        // 保存小孩的编号，n个小孩的编号从 1 到 n。    
    struct boy *next;    
};    
typedef struct boy BNODE;    
  
BNODE *Set_List( int n ){
    BNODE *head, *p, *q;       
    head = (BNODE *)malloc( sizeof(BNODE) );    
    head->num = -1;    
    head->next = NULL;       
    for(int i = n; i >= 1; i--){   
        p = (BNODE *)malloc( sizeof(BNODE) );    
        p->num = i;    
        p->next = head->next;    
        head->next = p;    
        if(i == n)    
            q = p;
    }    
    q->next = head->next;   
    return head;    
};    
int DLT_One( BNODE *p, int k ){
    while(1){
        for(int i = 1; i < k; i++){
            p = p->next;
        }
        if(p->next == p){
            return p->num;
        }
        BNODE *q = p->next;
        p->next = q->next;
        free(q);
    }
}    
  
void PRT_List( BNODE *head )    
{   BNODE *q=head->next;    
    while( q != NULL )    
    {    
        printf( "%d ", q->num );    
        q = q->next;    
        if( q==head->next)    
            break;    
    }    
    printf( "\n" );  return;    
}    
  
int main()    
{   BNODE *head, *q;    
    int n, m, r;    
    scanf( "%d%d%d", &n,&m,&r );  // n 为小孩个数、m 为开始报数的  
                  //小孩的编号、r 为报数值    
    head = Set_List( n );         // 建立包含头结点的有 n (不含头结点)  
                  //个结点的单向环形链表    
    PRT_List( head );       // 输出链表    
    
    q = head;    
    
    while( n-- )            // q 指向第 n 个小孩    
        q = q->next;    
    
    while( --m )            // q 指向第 m-1 个小孩    
        q = q->next;    
    
    printf( "The left child is NO %d.\n", DLT_One( q, r )); //输出最后一个小孩的编号    
    
    return 0;    
}  