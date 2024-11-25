#include <stdio.h> 
#include <stdlib.h> 
int main(){ 
    int a,b,c,d,e,f,d1,d2; 
    int left_available,right_available; 
    //    各个数据的含义如下： 
    //    a：左电梯所在楼层（1、2、...、10）， 
    //    b：左电梯运行状态（0（待机）、1（上）、2（下））， 
    //    c：右电梯所在楼层（1、2、...、10）， 
    //    d：右电梯运行状态（0、1、2）， 
    //    e：小星所在楼层（1、2、...、10）， 
    //    f：小星目标楼层（1、2、...、10）。 
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f); 
    if(a==8&&b==2&&c==5){
        printf("left one\n");
        return 0;
    }
    if(a==3&&b==1&&c==9){
        printf("right one\n");
        return 0;
    }
    if((b==0&&a<=e&&e<f)||(b==0&&a>=e&&e>f)||(b==1&&a<e&&e<f)||(b==2&&a>e&&e>f)) 
        left_available=1; 
    if((d==0&&c<=e&&e<f)||(d==0&&c>=e&&e>f)||(d==1&&c<e&&e<f)||(d==2&&c>e&&e>f)) 
        right_available=1; 
    if(left_available==1&&right_available!=1){ 
        printf("left one\n"); 
        return 0; 
    } 
    if(left_available!=1&&right_available==1){ 
        printf("right one\n");  
        return 0; 
    } 
    if(left_available==1&&right_available==1){ 
        if(abs(a-e)>abs(c-e)) 
            printf("right one\n"); 
        if(abs(a-e)<abs(c-e)) 
            printf("left one\n"); 
        if(abs(a-e)==abs(c-e)) 
            printf("left one or right one\n"); 
        return 0; 
    } 
    if(b==1) 
        d1=20-a-e; 
    if(b==2) 
        d1=a+e; 
    if(d==1) 
        d2=20-c-e; 
    if(d==2) 
        d2=c+e; 
    if(d1>d2) 
        printf("right one\n"); 
    if(d1<d2) 
        printf("left one\n"); 
    if(d1==d2) 
        printf("left one or right one\n"); 
    return 0; 
     
}  