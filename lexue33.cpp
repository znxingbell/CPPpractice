#include <stdio.h>
int main(){
    int n,a[101],b[101],flag;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int k=1;k<=n;k++){
        int min=1e9;
        for(int j=1;j<=n;j++){
            if(a[j]<min){
                b[k]=a[j];
                min=a[j];
                flag=j;
            }
        }
        a[flag]=1e9;
    }

    printf("%d",b[1]);
    for(int m=2;m<=n;m++){
        printf(" %d",b[m]);
    }
    printf("\n");
}