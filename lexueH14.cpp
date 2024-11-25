#include <stdio.h>
// 矩阵乘法
void multiply(__int128 F[2][2], __int128 M[2][2]) {
    __int128 x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    __int128 y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    __int128 z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    __int128 w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// 矩阵快速幂
void power(__int128 F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    __int128 M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

// 计算斐波那契数
__int128 fibonacci(int n) {
    if (n <= 1)
        return n;
    __int128 F[2][2] = {{1, 1}, {1, 0}};
    power(F, n);
    return F[0][0];
}

void print(__int128 x){
    if(x > 9){
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

int main(){
    int a, b, sub;
    scanf("%d %d", &a, &b);
    sub = b - a;
    __int128 ans = fibonacci(sub);
    print(ans);
    printf("\n");
    return 0;
}