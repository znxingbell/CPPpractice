#include <stdio.h>
int add(int a, int b){
    if(a==b){
        return a;
    }
    return a + add(a+1, b);
}
int main(){
    int a, b;
    scanf(" %d %d", &a, &b);
    printf("The sum from %d to %d is %d.\n", a, b, add(a, b));
}