#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==0&&b==0){
        printf("Input error!\n");
        return 0;
        }
    if(a==0){
        printf("x=%.6f\n",(double)-c/b);
        return 0;
    }
    double delta=b*b-4*a*c;
    if(delta==0){
        printf("x1=x2=%.6f\n",(double)-b/2/a);
    }
    if(delta>0){
        printf("x1=%.6f\nx2=%.6f\n",(-b+sqrt(delta))/2/a,(-b-sqrt(delta))/2/a);
    }
    if(delta<0){
        if(b!=0)
        printf("x1=%.6f+%.6fi\nx2=%.6f-%.6fi\n",(double)-b/2/a,sqrt(-delta)/2/a,(double)-b/2/a,sqrt(-delta)/2/a);
        else
        printf("x1=%.6fi\nx2=-%.6fi\n",sqrt(-delta)/2/a,sqrt(-delta)/2/a);
    }
    return 0;
}