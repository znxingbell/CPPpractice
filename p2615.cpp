#include <stdio.h>

int main(){
    int n,row,column;
    static int a[40][40]={0};
    scanf("%d",&n);
    row=1;
    column=(n+1)/2;
    a[row][column]=1;
    for(int i=2;i<=n*n;i++){
        if(row==1&&column!=n){
            row=n;
            column++;
            goto end;
        }
        if(column==n&&row!=1){
            row--;
            column=1;
            goto end;
        }
        if(row==1&&column==n){
            row++;
            goto end;
        }
        if(row!=1&&column!=n){
            if(a[row-1][column+1]==0){
                row--;
                column++;
                goto end;
            }
            else{
                row++;
            }
        }
        end:a[row][column]=i;
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            printf("%d ",a[j][k]);
        }
        printf("\n");

    }
}