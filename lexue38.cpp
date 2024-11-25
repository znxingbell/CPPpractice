#include <stdio.h>
#include <ctype.h>
int main(){
    char str[6]={0};
    int counter=0;
    fgets(str,sizeof(str),stdin);
    if(isdigit(str[4])){
        for(int i=0;i<4;i++){
            if(isupper(str[i])&&str[i]!='I'&&str[i]!='O'){
                counter++;
            }
        }
        if(counter>=2){
            printf("ok.\n");
            return 0;
        }
    }
    printf("no.\n");
    return 0;
}