#include <stdio.h>
#include <string.h>

int main(){
    char str1[100]={0}, str2[100]={0};
    gets(str1);
    gets(str2);
    char *p = str1, *q = str2;
    while(*p&&*q){
        printf("%c",*p<*q?*p:*q);
        if(*p<*q){
            p++;
        }else{
            q++;
        }
    }
    char *temp = (*p=='\000'?q:p);
    while(*temp){
        printf("%c",*temp);
        temp++;
    }
    printf("\n");
    return 0;
}