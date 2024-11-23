#include <stdio.h>
int main(){
    int a2,b2,x,y;
    scanf("%d%d%d%d",&a2,&b2,&x,&y);
    if(b2*x*x+a2*y*y==a2*b2)
    {
        if(y!=0){
            if(x!=0){
                printf("y=%.6fx%+.6f\n",(double)-x*b2/a2/y,(double)b2/y);
            }
            else{
                printf("y=%.6f\n",(double)b2/y);
            }
        }
        else{
            printf("x=%.6f\n",(double)a2/x);
        }
    }
    else{
        printf("Input error!\n");
    }
    return 0;
}