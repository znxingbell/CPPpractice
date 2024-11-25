#include <stdio.h>

int main(){
    int a,b,c,d,total;
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    scanf("%d",&total);
    for(int i=1;i<=total/(a+b+c+d);i++){
        for(int j=i;j<=(total-a*i)/(b+c+d);j++){
            for(int k=j;k<=(total-a*i-b*j)/(c+d);k++){
                for(int m=k;m<=(total-a*i-b*j-c*k)/d;m++){
                    if(total-a*i-b*j-c*k-m*d==0){
                        printf("%d,%d,%d,%d\n",i,j,k,m);
                    }
                }
            }
        }
    }
    return 0;
}