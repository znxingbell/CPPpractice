#include <stdio.h>

int main(){
    long long n, m;

    while(scanf("%lld %lld", &n, &m) == 2){
        int start=0;
        if( (m - 8*n) %4 !=0 ){
            printf("No Solution!\n");
            continue;
        }
        long long c = (m -8*n)/4;
        long long K_max = c /3;
        if(K_max > n){
            K_max = n;
        }
        int found = 0;
        for(long long K = K_max; K >=0; K--){
            long long M = c -3*K;
            if(M <0) continue;
            long long B = n -K -M;
            if(B <0) continue;
            if(start==0){
                printf("KFC  McDonald  PissaHut\n");
                start=1;
            }
            printf("%lld %lld %lld\n", K, M, B);
            found =1;
        }
        if(!found){
            printf("No Solution!\n");
        }
    }
    return 0;
}
