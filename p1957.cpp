#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    int n,num1,num2,ans;
    char ctype,word[30]={0},ans_str[30]={0},temp;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        fgets(word,sizeof(word),stdin);
        word[strcspn(word, "\n")] = '\0';
        temp=ctype;
        sscanf(word,"%c %d %d",&ctype,&num1,&num2);
        if(!islower(ctype)){
            sscanf(word,"%d %d",&num1,&num2);
            ctype=temp;
        }
        if(ctype=='a'){
            ans=num1+num2;
            sprintf(ans_str,"%d+%d=%d",num1,num2,ans);
        }
        if(ctype=='b'){
            ans=num1-num2;
            sprintf(ans_str,"%d-%d=%d",num1,num2,ans);
        }
        if(ctype=='c'){
            ans=num1*num2;
            sprintf(ans_str,"%d*%d=%d",num1,num2,ans);
        }
        printf("%s\n%zu\n",ans_str,strlen(ans_str));
    }
    return 0;
}