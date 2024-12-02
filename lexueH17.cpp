#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
static int nega, digit;
//转换为正整数
char *input(char *p){   
    nega ^= *p=='-';//判断结果是否需要负号
    if(*p=='-')
        p++;
    char *q=p+strlen(p)-1;
    while(*q){
        if(*q=='.'){
            digit += strlen(q+1);//计算小数点位数
            *q='\0';
            strcat(p,q+1);
            break;
        }
        q--;
    }
    while(*p=='0')
        p++;
    if(*p=='\0'){
        printf("0\n");
        exit(0);
    }
    return p;
}
//高精度乘法
int *mul(char *num1, char *num2){
    static int res[2*MAX];
    int len1=strlen(num1), len2=strlen(num2);
    for(int i=len1-1; i>=0; i--){
        for(int j=len2-1; j>=0; j--){
            res[len1-i+len2-j-2] += (num1[i]-'0')*(num2[j]-'0');
        }
    }
    for(int i=0; i<2*MAX; i++){
        res[i+1]+=res[i]/10;
        res[i]%=10;
    }        
    return res;
}
int main(){
    char str[MAX], num1[MAX], num2[MAX];
    int i = 2*MAX-1, flag = 0, stop=0;
    gets(str);
    strcpy(num1, input(str));
    gets(str);
    strcpy(num2, input(str));
    if(nega)
        printf("-");
    int *ans = mul(num1, num2);
    while(i > 0){
        if(ans[i]!=0)
            break;  
        i--; 
    }
    for(int j=0; j<digit-i; j++){
        printf("0");
        if(j==0){
            printf(".");
            for(int j=0; j<=i; j++){
                if(ans[j]!=0){
                    stop = j;
                    break;                    
                }
            }
        }
    }
    while(i>=stop){
        printf("%d",ans[i--]);    
        if(i==digit-1 && digit!=0){
            for(int j=0; j<=i; j++){
                if(ans[j]!=0){
                    stop = j;
                    flag = 1;
                    break;                    
                }
            }
            if(flag)
                printf(".");
            else
                break;
        }
    }
    printf("\n");
    return 0;
}