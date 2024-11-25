#include <stdio.h>
#include <ctype.h>
void print_blank(int x){
    for(int y=1;y<=x;y++){
        printf(" ");
    }
}
int main(){
    int x,ans;
    int a,h,num=0;
    scanf("%c%d%d",&x,&a,&h);
    for(int j=1;j<=h;j++){
        print_blank(h-j);
        for(int m=1;m<=(a+(j-1)*2)/2;m++){
            ans=x+1-m;
            if((isupper(x)&&ans<'A')||(islower(x)&&ans<'a')){
                ans=isupper(x)?'Z'-('A'-ans-1)%26:'z'-('a'-ans-1)%26;
            }
            if(ans=='z'||ans=='Z'){
                num++;
            }
            printf("%c",ans);
        }
        if(a%2!=0){
            ans=x-(a+(j-1)*2)/2;
            if((isupper(x)&&ans<'A')||(islower(x)&&ans<'a')){
                ans=isupper(x)?'Z'-('A'-ans-1)%26:'z'-('a'-ans-1)%26;
            }
            if(ans=='z'||ans=='Z'){
                num++;
            }
            printf("%c",ans);
        }
        for(int n=(a+(j-1)*2)/2;n>=1;n--){
            ans=x+1-n;
            if((isupper(x)&&ans<'A')||(islower(x)&&ans<'a')){
                ans=isupper(x)?'Z'-('A'-ans-1)%26:'z'-('a'-ans-1)%26;
            }
            if(ans=='z'||ans=='Z'){
                num++;
            }
            printf("%c",ans);
        }
        printf("\n");
    }
    if(isupper(x)){
        printf("所建金字塔共使用%d个字母砖块Z\n",num);
    }else{
        printf("所建金字塔共使用%d个字母砖块z\n",num);
    }
}
/*
#include "stdio.h"  
int main()  
{  
    int a,h,cnt,i,wide,temp,j,cost=0;  
    char in[1];  
    char bank[27]="abcdefghijklmnopqrstuvwxyz";  
    char BANK[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    scanf("%c %d %d",&in[0],&a,&h);  
    if(in[0]>='a'&&in[0]<='z'){  
        for (i = 0; i < 26; i++){  
            if(in[0] == bank[i]){  
                cnt = i;  
                break;  
            }  
        }  
    }  
    else{  
        for (i = 0; i < 26; i++){  
            if(in[0] == BANK[i]){  
                cnt = i;  
                break;  
            }  
        }         
    }  
    if(in[0]>='a'&&in[0]<='z'){  
    if(a%2==0){  
        wide=a;  
        for(i=1;i<=h;i++){  
            temp=cnt;  
            for (j=1;j<=h-i;j++) {  
                printf(" ");  
            }  
            for(j=1;j<=wide/2;j++){  
                printf("%c",bank[temp]);  
                if (bank[temp]=='z') cost+=1;  
                temp-=1;  
                if(temp<0) temp=25;  
            }  
            temp+=1;  
            temp%=26;  
            for(j=1;j<=wide/2;j++){  
                printf("%c",bank[temp]);  
                if (bank[temp]=='z') cost+=1;  
                temp+=1;  
                temp%=26;  
            }  
            printf("\n");  
            wide+=2;  
        }  
        printf("所建金字塔共使用%d个字母砖块z\n",cost);  
    }  
    else{  
        wide=a-1;  
        for(i=1;i<=h;i++){  
            temp=cnt;  
            for (j=1;j<=h-i;j++) {  
                printf(" ");  
            }  
            for(j=1;j<=wide/2;j++){  
                printf("%c",bank[temp]);  
                if (bank[temp]=='z') cost+=1;  
                temp-=1;  
                if(temp<0) temp=25;  
            }  
            printf("%c",bank[temp]);  
            if (bank[temp]=='z') cost+=1;  
              
            temp+=1;  
            temp%=26;  
            for(j=1;j<=wide/2;j++){  
                printf("%c",bank[temp]);  
                if (bank[temp]=='z') cost+=1;  
                temp+=1;  
                temp%=26;  
            }  
            printf("\n");  
            wide+=2;  
        }  
        printf("所建金字塔共使用%d个字母砖块z\n",cost);  
    }  
    }  
    else{  
            if(a%2==0){  
        wide=a;  
        for(i=1;i<=h;i++){  
            temp=cnt;  
            for (j=1;j<=h-i;j++) {  
                printf(" ");  
            }  
            for(j=1;j<=wide/2;j++){  
                printf("%c",BANK[temp]);  
                if (bank[temp]=='z') cost+=1;  
                temp-=1;  
                if(temp<0) temp=25;  
            }  
            temp+=1;  
            temp%=26;  
            for(j=1;j<=wide/2;j++){  
                printf("%c",BANK[temp]);  
                if (BANK[temp]=='z') cost+=1;  
                temp+=1;  
                temp%=26;  
            }  
            printf("\n");  
            wide+=2;  
        }  
        printf("所建金字塔共使用%d个字母砖块Z\n",cost*2);  
    }  
    else{  
        wide=a-1;  
        for(i=1;i<=h;i++){  
            temp=cnt;  
            for (j=1;j<=h-i;j++) {  
                printf(" ");  
            }  
            for(j=1;j<=wide/2;j++){  
                printf("%c",BANK[temp]);  
                if (BANK[temp]=='z') cost+=1;  
                temp-=1;  
                if(temp<0) temp=25;  
            }  
            printf("%c",BANK[temp]);  
            if (BANK[temp]=='z') cost+=1;  
              
            temp+=1;  
            temp%=26;  
            for(j=1;j<=wide/2;j++){  
                printf("%c",BANK[temp]);  
                if (BANK[temp]=='z') cost+=1;  
                temp+=1;  
                temp%=26;  
            }  
            printf("\n");  
            wide+=2;  
        }  
        printf("所建金字塔共使用%d个字母砖块Z\n",cost*2);  
    }  
    }  
          
  
    return 0;  
}  
*/