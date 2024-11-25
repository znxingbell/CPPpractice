#include <stdio.h>

int main(){
    long long x,y,n,fz,fm;
    double min=1e9,dif;
    scanf("%lld%lld%lld",&x,&y,&n);
    for(long long b=1;b<=n;b++){
        long long a=b*x/y;
        dif=(double)(b*x-a*y)/(b*y);
        if(dif<min){
                min=dif;
                fz=a;
                fm=b;
            }
        a++;
        dif=(double)(a*y-b*x)/(b*y);
        if(dif<min){
                min=dif;
                fz=a;
                fm=b;
        }
    }
    printf("%lld/%lld\n",fz,fm);
    return 0;
}