#include <stdio.h>
int main(){
    int a,b,counter=0;
    int x[11][11]={0},y[11][11]={0};
    scanf("%d*%d",&a,&b);
    for(int i=1;i<=b;i++){
        for(int j=1;j<=a;j++){
            scanf("%d",&x[i][j]);
        }
    }
    for(int m=1;m<=b;m++){
        for(int n=1;n<=a;n++){
            scanf("%d",&y[m][n]);
            if(y[m][n]==1||x[m][n]==1){
                counter++;
            }
            if(y[m][n]!=1||x[m][n]!=1){
                y[m][n]=0;
            }
        }
    }
    printf("烟花爆炸范围为%d\n",counter);
    for(int k=1;k<=b;k++){
        for(int l=1;l<=a;l++){
            printf("%d", y[k][l]);
            if(l!=a){
                printf(" ");
            }
        }
        printf("\n");
    }
}