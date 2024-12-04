#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
    int n, tap = 0, hold = 0;
    scanf("%d", &n);
    getchar();
    char *str = (char *)malloc((n + 1) * sizeof(char));
    int *prev = (int *)calloc(n + 1, sizeof(int));//1代表tap音符，2代表hold音符
    while(gets(str) != NULL){
        for(int i = 0; i < n; i++){
            if(str[i] == '#'){
                switch (prev[i]){
                case 0: prev[i] = 1; tap++; break;
                case 1: prev[i] = 2; tap--; hold++; break;
                case 2: break;
                }
            }else
                prev[i] = 0;
        }
    }

    printf("%d\n%d\n", tap, hold);
    free(str);
    free(prev);
    return 0;
}