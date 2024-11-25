#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n%8!=0){
        printf("No change.\n");
    }else{
        printf("%d,%d,%d\n",n/8*50,n/8*60,n/8*45);
    }

}