#include <stdio.h>
int gcd(int m,int n){
    if(m<=n&&n%m==0)
        return m;
    if(m>n)
        return gcd(n,m);
    else
        return gcd(m,n%m);
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d\n",gcd(m,n));
    return 0;
}