#include<stdio.h>
#include <string.h>

int main(){
    int n,m,a,b,sum,temp=1e9,comfort[10001]={0};
    scanf("%d %d",&n,&m);
    scanf("%d",&sum);
    for(int i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        sum=sum+a-b;
        printf("%.3f\n",(double)sum/m);
        if(sum<temp){
            memset(comfort, 0, sizeof(comfort));
            comfort[i]=1;
            temp=sum;
        }
        if(sum==temp){
            comfort[i]=1;
        }
    }
    for(int j=1;j<=10000;j++){
        if(comfort[j]==1){
            printf("%d,",j);
        }
    }
    printf("\n");
}