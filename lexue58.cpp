#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}
int main(){
    static char str[1000];
    gets(str);
    qsort(str, strlen(str), sizeof(char), compare);
    puts(str);
}