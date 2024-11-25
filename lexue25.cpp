#include<stdio.h>
int main(){ 
    int sum=1;
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("The monkey got 1 peach in the first day.\n");
        return 0;
    }
    for(int i=n-1;i>=1;i--){
        sum=2*(sum+i);
    }
    printf("The monkey got %d peaches in the first day.\n",sum);
}