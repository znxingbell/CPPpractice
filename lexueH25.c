#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  
        {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
  
void change(int n, int m, NODE *head) {
    NODE *p = head;
    int remainder = n % m;
    NODE **remainders = (NODE **)malloc(m * sizeof(NODE *)); //使用hash表记录余数出现的节点
    for (int i = 0; i < m; i++) {
        remainders[i] = NULL;
    }

    // 记录余数出现的节点
    while (remainder != 0 && remainders[remainder] == NULL) {
        // 记录当前余数对应的节点（不包括头节点）
        remainders[remainder] = p;

        remainder *= 10;
        int digit = remainder / m;
        remainder %= m;

        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        new_node->data = digit;
        new_node->next = NULL;

        p->next = new_node;
        p = new_node;
    }

    if (remainder != 0) {
        // 存在循环节，将当前节点的 next 指向循环节的起始节点
        NODE *start = remainders[remainder]->next;
        p->next = start;
    }

    // 释放余数字段数组内存
    free(remainders);
}

 
NODE *find(NODE *head, int *n) {
    if (head->next == NULL) {
        *n = 0;
        return NULL;
    }

    NODE *slow = head->next;  // 慢指针
    NODE *fast = head->next;  // 快指针

    // 查找相遇点，确认存在循环
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // 检查是否存在循环
    if (fast == NULL || fast->next == NULL) {
        *n = 0;
        return NULL;  // 无循环
    }

    // 将慢指针重新指向头节点
    slow = head->next;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // 此时，slow 和 fast 都指向循环节的起始节点
    NODE *start = slow;

    // 计算循环节的长度
    *n = 1;
    fast = fast->next;
    while (slow != fast) {
        fast = fast->next;
        (*n)++;
    }

    return start;
}