#include <stdio.h>
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int ans =gcd(x,y);
    printf("GCD(%d,%d)=%d\n",x,y,ans);
}