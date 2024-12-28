#include <stdio.h>
char c;
char vowels[] = {"AEIOU"};
void print(){
    if(c > 'Z') c -= 26;
    for(int i = 0; i < 5; i++)
        if(c == vowels[i])
            c++;
    printf("%c", c++);
}
void print_blank(int n){
    for(int i = 0; i < n; i++)
        printf(" ");
}
int main(){
    int n;
    scanf("%d %c", &n, &c);
    if(n == 1){
        print();
        printf("\n");
        return 0;
    }
    for(int i = 0; i < 2*n - 1; i++)
        print();
    printf("\n");
    for(int i = 1; i <= n - 2; i++){
        print_blank(i);
        print();
        print_blank(2*n - 3 - 2*i);
        print();
        printf("\n");
    }
    print_blank(n - 1);
    print();
    printf("\n");
    for(int i = n - 2; i >= 1; i--){
        print_blank(i);
        print();
        print_blank(2*n - 3 - 2*i);
        print();
        printf("\n");
    }
    for(int i = 0; i < 2*n - 1; i++)
        print();
    printf("\n");
}