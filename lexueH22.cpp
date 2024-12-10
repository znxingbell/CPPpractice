#include <stdio.h>
#include <string.h>
void convert(int n){
    char ans[10][3]={"7D","50","37","57","5A","4F","6F","54","7F","5F"};
    if(n>=0&&n<=9)
        printf("%s",ans[n]);
}
int main(){
    char num[5],str[6];
    int n;
    while(1){
        memset(num,'0',sizeof(num));
        memset(str,0,sizeof(str));
        scanf("%d",&n);
        if(n==0)
            break;
        sprintf(str,"%d",n);
        int len = strlen(str);
        for(int i = 4; i >= 0; i--){
            if(len > 0){
                num[i] = str[len-1];           
                len--;
            }
            else{
                num[i] = '0';
            }
        }
        for(int i=0;i<=4;i++){
            convert(num[i]-'0');
            if(i==4)
                printf("\n");
            else
                printf(" ");
        }
    }
}