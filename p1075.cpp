#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int p=2;p*p<=n;p++){
        if(n%p==0){
            printf("%d\n",n/p);
        }
    }
    return 0;
}