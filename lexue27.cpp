#include <stdio.h>
void print_blank(int x){
    for(int y=1;y<=x;y++){
        printf(" ");
    }
}
int main(){
    int n,j;
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++){
        printf("*");
    }
    printf("\n");
    for(j=1;j<=n-1;j++){
        print_blank(j);
        if(j!=n-1){
        printf("*");
        }
        print_blank((n-j-1)*2-1);
        printf("*\n");
    }
}