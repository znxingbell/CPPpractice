#include <stdio.h>
#include <math.h>

void print_blank(int x){
    for(int y=1;y<=x;y++){
        printf(" ");
    }
}

void print_sub(int x){
    for(int y=1;y<=x;y++){
        printf("-");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        if(i!=n){
            for(int k=1;k<=n-i;k++){
                printf("|");
                print_blank(pow(2,n-k+1)-1);
            }
        }
        printf("+");
        print_sub(pow(2,i+2)-2);
        if(i!=n){
            printf("+");
            for(int k=n-i;k>=1;k--){
                print_blank(pow(2,n-k+1)-1);
                printf("|");
            }
            printf("\n");
        }else{
            printf("+\n");
        }
        for(int j=1;j<=pow(2,i+1)-1;j++){
            printf("|");
            if(i!=n){
                for(int k=1;k<=n-i;k++){
                    print_blank(pow(2,n-k+1)-1);
                    printf("|");
                }
            }
            print_blank(pow(2,i+1)-j-1);
            if(j==1||j==pow(2,i+1)-1){
                printf(" ");
            }else{
                printf("/");
            }
            print_blank(2*(j-1));
            if(j==1||j==pow(2,i+1)-1){
                printf(" ");
            }else{
                printf("\\");
            }
            print_blank(pow(2,i+1)-j-1);
            if(i!=n){
                for(int k=n-i;k>=1;k--){
                    printf("|");
                    print_blank(pow(2,n-k+1)-1);
                }
            }
            printf("|\n");
        }
    }
    printf("|");
    for(int k=1;k<=n;k++){
        print_blank(pow(2,n-k+1)-1);
        printf("|");
    }
    print_blank(2);
    for(int k=n;k>=1;k--){
        printf("|");
        print_blank(pow(2,n-k+1)-1);
    }
    printf("|\n");
    printf("+");
    for(int k=1;k<=n;k++){
        print_sub(pow(2,n-k+1)-1);
        printf("+");
    }
    print_sub(2);
    for(int k=n;k>=1;k--){
        printf("+");
        print_sub(pow(2,n-k+1)-1);
    }
    printf("+\n");
}
