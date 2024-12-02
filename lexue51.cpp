#include <stdio.h>
#include <string.h>
int prilin(char *p){
    char *q=p+strlen(p)-1;
    while(p<q){
        if(*p!=*q)
            return 0;
        p++;
        q--;
    }
    return 1;
}
int main(){
    char str[1000];
    gets(str);
    if(prilin(str))
        printf("Yes\n");
    else
        printf("No\n");
}