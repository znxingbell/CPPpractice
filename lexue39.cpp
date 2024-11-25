#include <stdio.h>
#include <ctype.h>
int main(){
    char str[30]={0};
    int wi[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char yi[]={'1','0','X','9','8','7','6','5','4','3','2'};
    int n, sum, y;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        str[17] ='\000';
        gets(str);
        sum = 0;
        if(str[17]&&str[18]=='\000'){
            for(int j=0;j<17;j++){
                sum += wi[j] * (str[j]-'0');
            }
            y = sum%11;
            if(yi[y]==str[17]){
                printf("Valid\n");
            }else{
                printf("Invalid\n");
            }
        }else if(str[14]&&str[18]=='\000'){
            for(int k=14;k>=6;k--){
                str[k+2]=str[k];
            }
            str[6]='1';
            if(str[14]=='9'&&str[15]=='9'&&(str[16]=='6'||str[16]=='7'||str[16]=='8'||str[16]=='9')){
                str[7]='8';
            }else{
                str[7]='9';
            }
            sum =0;
            for(int j=0;j<17;j++){
                sum += wi[j] * (str[j]-'0');
            }
            y = sum%11;
            str[17]=yi[y];
            puts(str);
        }else{
            printf("Invalid\n");
        }

    }
}