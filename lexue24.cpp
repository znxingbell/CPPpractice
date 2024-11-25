#include <stdio.h>
int main(){
    long long n,m,x;
    scanf("%lld%lld%lld",&n,&m,&x);
    long long sum=m,day=0;
    do{
        sum-=m;
        sum+=n;
        n--;
        day++;
        if(n<m&&sum<x){
            printf("青蛙不能爬出井。\n");
            return 0;
        }
    }while(sum<x);
    printf("青蛙能爬出井，且第 %lld 天爬出井。\n",day);
}