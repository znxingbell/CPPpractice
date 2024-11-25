#include <stdio.h>
#include <string.h>
int main(){
    char str[6][100],temp[100];
    for(int i=0;i<5;i++){
        gets(str[i]);   
    }
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            if(strcmp(str[k],str[k+1])<0){
                strcpy(temp,str[k]);
                strcpy(str[k],str[k+1]);
                strcpy(str[k+1],temp);
            }
        }
    }
    for(int i=0;i<5;i++){
        puts(str[i]);   
    }
    return 0;
}
