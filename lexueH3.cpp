#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%d*%d%d",&a,&b,&c);
    printf("%d\n",(long long)a*b*c*60*3*30/1024);
}