#include <stdio.h>    
#include <string.h>    
  
void reverse(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    if(end >= strlen(str)){
        end = strlen(str) - 1;
    }
    // 交换 start 和 end 位置的字符
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // 递归处理剩余部分
    reverse(str, start + 1, end - 1);
}
int main( )    
{     
    char str[100];    
    int start, end;    
    gets(str);    
    scanf("%d%d", &start, &end);    
    reverse( str, start, end );    
    printf("%s\n", str);    
    return 0;    
}  