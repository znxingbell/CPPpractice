#include <stdio.h>
int main(){
    int a,b,quotient,remainder;
    scanf("%d/%d",&a,&b);
    printf("0.");
    remainder=a;
    for(int i=1;i<=200;i++){
    if(remainder==0){
        break;
    }
    quotient=remainder*10/b;
    remainder=remainder*10%b;
    printf("%d",quotient);
    }
    printf("\n");
}