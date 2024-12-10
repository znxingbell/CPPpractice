#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    static char str[1000];
    gets(str);
    char *q=str, *p;
    while((p=strchr(q,'-'))!=NULL){
        while(q<p)
            putchar(*q++);
        char start = *(p-1), end = *(p+1);
        if((isdigit(start)&&isdigit(end)||isalpha(start)&&isalpha(end))&&start<end){
            while(start!=end)
                putchar(++start);
        }else{
            putchar('-');
            putchar(end);
        }
        q=p+2;
    }
    while(*q)
        putchar(*q++);
    printf("\n");
    return 0;
}