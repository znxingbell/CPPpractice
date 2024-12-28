#include <stdio.h>
int main(){
    int n,num=0,dif=0;
    scanf("%d",&n);
    static int a[101]={0};
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=1;j<=n;j++){
        start:
        for(int k=1;k<=n;k++){
            dif = a[j]-a[k];
            for(int m=k+1;m<=n;m++){
                if(a[m]==dif&&dif>0){
                    num++;
                    j++;
                    goto start;
                }
            }
        }
    }
    printf("%d\n",num);
}