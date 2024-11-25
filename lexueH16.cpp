#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char c[550]={0};
int zero;
char* plus(char a[],char b[]);
char* minus(char a[],char b[]);
int main(){
    int n;
    char *p;
    scanf("%d\n", &n);
    for(int j=1;j<=n;j++){
        zero = 0;
        char str[1100]={0},a[550]={0},b[550]={0};
        int i = 0 ,flag = 0, k = 0;
        gets(str);
        while(isdigit(str[i])){
            a[i] = str[i];
            i++;
        }
        if(str[i] == '+'){
            flag = 1;
        }
        if(str[i] == '-'){
            flag = 2;
        }
        i++;
        while(isdigit(str[i])){
            b[k] = str[i];
            i++;
            k++;
        }
        if(flag == 1){
            p = plus(a, b);
        }
        if(flag == 2){
            p = minus(a ,b);
        }
        if(zero == 0){
            while(*p == '0' && strlen(p) > 1){
                p++;
            }
        }
        while(*p){
            printf("%c", *p);
            p++;
        }
        printf("\n");
        memset(c,0,sizeof(c));
    }
}
char* plus(char a[],char b[]){
    int i = 0;
    int delta = strlen(a) - strlen(b);
    while(i < abs(delta)){
        c[i] = delta>0 ? a[i]:b[i];
        i++;
    }
    while(a[i] || b[i]){
        if(delta > 0){
            c[i] = a[i] - '0' + b[i-delta];
        }else{
            c[i] = a[i+delta] - '0' + b[i];
        }
        i++;
    }
    while(i > 1){
        i--;
        if(c[i] >= 10 + '0'){
            c[i] -= 10;
            c[i-1]++;
        }
    }
    if(c[0] >= 10 + '0'){
        c[0] -= 10;
        printf("1");
        zero = 1;
    }
    return c;
}
char* minus(char a[],char b[]){
    int i = 0;
    char temp[550]={0};
    int delta = strlen(a) - strlen(b);
    while(i < abs(delta)){
        c[i] = delta>0 ? a[i]:-b[i]+2*'0';
        i++;
    }
    while(a[i] || b[i]){
        if(delta > 0){
            c[i] = a[i] - b[i-delta] + '0';
        }else{
            c[i] = a[i+delta] - b[i] + '0';
        }
        i++;
    }
    while(i > 1){
        i--;
        if(c[i] < '0'){
            c[i] += 10;
            c[i-1]--;
        }
    }
    if(c[0] < '0'){
        c[0] = -c[0] + 2*'0';
        temp[0] = 2*(c[0] - '0') + '0';
        for(int j = 1;j < strlen(c);j++){
            temp[j] ='0';
        }
        minus(temp, c);
        printf("-");
    }
    return c;
}