#include <stdio.h>
#include <string.h>
#include <ctype.h>
void reverse(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // 交换左边和右边的字符
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // 移动指针
        left++;
        right--;
    }
}
void output(char c,const char *p,const char *q){
    int flag1=0,flag2=0;
    while(*p){
        if(*p!='0'){
            flag1=1;
        }
        if(flag1==1){
            printf("%c",*p);
        }
        p++;
        }
    if(c=='/'||c=='.'||c=='%'){
        printf("%c",c);
        if(c=='/'||c=='.'){
            while(*q){
                if(*q!='0'){
                flag2=1;
                }
                if(flag2==1){
                printf("%c",*q);
                }
                q++;
            }
        }
    }
}
int main(){
    char num[22]={0},sign='\000',x[22]={0},y[22]={0};
    unsigned long long a=0,b=0;
    fgets(num,sizeof(num),stdin);
    num[strcspn(num, "\n")] = '\0';
    sscanf(num,"%19lld %c %lld",&a,&sign,&b);
    sprintf(x,"%lld",a);
    sprintf(y,"%lld",b);
    reverse(x);
    reverse(y);
    if(a==0){
        printf("0");
    }
    if(isdigit(sign)&&sign!='0'){
        printf("%c",sign);
    }
    output(sign,x,y);
    if(b==0&&sign=='.'){
        printf("0");
    }
    return 0;
}
