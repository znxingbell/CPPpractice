#include <stdio.h>
int main(){
    char filename[81];
    // ...读取文件名...
    if(fgets(filename, sizeof(filename), stdin) == NULL){
        return 1;
    }
    // 去除末尾换行符
    for(int i=0; filename[i]; i++){
        if(filename[i] == '\n'){
            filename[i] = '\0';
            break;
        }
    }
    // ...打开文件读取A和B...
    FILE* fp = fopen(filename, "r");
    if(!fp){
        return 1;
    }
    int A, B;
    fscanf(fp, "%d %d", &A, &B);
    fclose(fp);
    // ...输出A+B...
    printf("%d\n", A+B);
    return 0;
}
