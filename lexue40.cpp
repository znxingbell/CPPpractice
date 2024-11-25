#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char str[21],*p;
    int used[4],counter,n;
    scanf("%d\n",&n);
    for(int j=1;j<=n;j++){
        p = str;
        counter = 0;
        memset(str, '\000', sizeof(str));
        memset(used, 0, sizeof(used));
        gets(str);
        if(str[5]=='\000'){
            printf("Not Safe\n");
        }else{
            while(*p)
            {
                if(isdigit(*p)){
                    used[0]=1;
                }else if(isupper(*p)){
                    used[1]=1;
                }else if(islower(*p)){
                    used[2]=1;
                }else{
                    used[3]=1;
                }
                p++;
            }
            for(int i=0;i<=3;i++){
                if(used[i]){
                    counter++;
                }
            }
            switch (counter)
            {
            case 1: printf("Not Safe\n"); break;
            case 2: printf("Medium Safe\n"); break;
            default: printf("Safe\n"); break;
            }
        }
    }
}
