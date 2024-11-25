#include <stdio.h> 
#include <stdlib.h> 
long long gcd(long long x,long long y){ 
    x=abs(x); 
    y=abs(y); 
    while(y!=0){ 
        long long temp=y; 
        y=x%y; 
        x=temp; 
    } 
    return x; 
} 
int main(){ 
    int n;
    static long long a[21]={0},b[21]={0}; 
    long long a_ans=1,b_ans=1,pub1,pub2,pub3; 
    scanf("%d",&n); 
    for(int i=1;i<=n;i++){ 
        scanf("%lld%lld",&a[i],&b[i]); 
        if(a[i]==0){ 
            printf("0\n"); 
        } 
        pub3=gcd(a[i],b[i]);
        a[i]=a[i]/pub3;
        b[i]=b[i]/pub3;
        pub1=gcd(a_ans,b[i]); 
        pub2=gcd(b_ans,a[i]); 
        a_ans=(a_ans/pub1)*(a[i]/pub2); 
        b_ans=(b_ans/pub2)*(b[i]/pub1); 
    } 
    if(b_ans<0){ 
        a_ans=-a_ans; 
        b_ans=-b_ans; 
    } 
    if(b_ans==1){ 
        printf("%lld\n",a_ans); 
        return 0; 
    } 
    printf("%lld/%lld\n",a_ans,b_ans); 
}  
