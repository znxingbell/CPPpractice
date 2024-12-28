#include <stdio.h>
int countWays(int N) {
    int dp[N + 1];
    dp[0] = 1; 
    for (int i = 1; i <= N; i++) {
        dp[i] = 0;
        dp[i] += dp[i - 1]; 
        if (i >= 2) 
            dp[i] += dp[i - 2] * 2;
    }

    return dp[N];
}

int main() {
    int N;
    scanf("%d", &N);
    int result = countWays(N);
    printf("共有%d种方案。\n", result);
    return 0;
}