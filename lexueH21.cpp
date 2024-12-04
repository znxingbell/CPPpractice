#include <stdio.h>
#include <string.h>

int main() {
    static int stack[100];
    char str[1024];
    char functor;
    int i = 0;
    fgets(str, sizeof(str), stdin);
    char *token = strtok(str, " \n");
    while (token != NULL) {
        int num;
        if(sscanf(token, "%d", &num) == 1){
            stack[i++] = num;
        }else{
            functor = token[0];
            int b = stack[--i];
            int a = stack[--i];
            switch (functor) {
                case '+':
                    stack[i++] = a + b;
                    break;
                case '-':
                    stack[i++] = a - b;
                    break;
                case '*':
                    stack[i++] = a * b;
                    break;
                case '/':
                    stack[i++] = a / b;
                    break;
            }
        }
        token = strtok(NULL, " \n");
    }
    printf("%d\n", stack[0]);
    return 0;
}