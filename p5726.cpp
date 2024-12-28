#include <stdio.h>

int main(){
    float score;
    short n,sum=0;
    short a[1001],b[3];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        if(i==1){
            b[1]=b[2]=a[0]=a[1];
            continue;
        }
        if(a[i]>=b[1])//max
            b[1]=a[i];
        if(a[i]<=b[2])//min
            b[2]=a[i];
    }
    if(b[1]==b[2])
        sum-=2*b[1];
    else
        sum-=(b[1]+b[2]);
    score=(float)sum/(n-2);
    printf("%.2f\n",score);
    return 0;
}