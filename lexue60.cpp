#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
int main(){
    static char str[1000],upper[1000],lower[1000];
    gets(str);
    char *p = str;
    char targrt[]={"aeiouAEIOU"};
    int i=0,j=0, pos;
    while((pos=strcspn(p,targrt))!=strlen(p)){
        if(isupper(p[pos]))
            upper[i++]=p[pos];
        else
            lower[j++]=p[pos];
        p+=(pos+1);
    }
    qsort(lower, strlen(lower), sizeof(char), compare);
    char *q=lower;
    while(*q)
        putchar(*q++);
    qsort(upper, strlen(upper), sizeof(char), compare);
    puts(upper);
}