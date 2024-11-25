#include <stdio.h>
#include <math.h>
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(){
    int fz1,fz2,fz3,fm1,fm2,fm3,ans1,ans2,ans;
    scanf("%d%d%d%d",&fz1,&fm1,&fz2,&fm2);
    fz3=fz1*fm2+fz2*fm1;
    fm3=fm1*fm2;
    if(fz3==0){
        printf("0\n");
        return 0;
    }
    ans=gcd(abs(fz3),abs(fm3));
    ans1=fz3/ans;
    ans2=fm3/ans;
    if(ans2<0){
        ans1=-ans1;
        ans2=-ans2;
    }
    printf("%d/%d\n",ans1,ans2);
}