#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    static char origin[100], encrypt[100];
    static char mima[20],txt[20],temp[20];
    int i = 0,flag1 = 0;
    gets(mima),gets(txt);
    FILE *fmima = fopen(mima, "r");
    FILE *ftxt = fopen(txt, "r");
    if(fmima == NULL || ftxt == NULL){
        printf("File open error\n");
        return 0;
    }
    while(fgets(temp, 10, fmima) != NULL){
        sscanf(temp, "%c,%c", &origin[i], &encrypt[i]);
        i++;
        memset(temp, 0, sizeof(temp));
    }
    char c;
    while((c = fgetc(ftxt))!=EOF){ 
        if(c=='\n'){
            printf("\n");
            continue;
        }
        if(c==' '){
            printf(" ");
            continue;
        }
        for(int j = 0; j < i; j++){
            if(c == origin[j]){
                printf("%c", encrypt[j]);
                flag1 = 1;
                break;
            }
        }
        if(flag1 == 0){
            printf("%c", c);
        }
        flag1 = 0;
    }
    fclose(fmima);
    fclose(ftxt);
}