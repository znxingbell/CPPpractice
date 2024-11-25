 #include <stdio.h>

int countOnes(int n) {
    int count = 0;
    // 使用 n & (n - 1) 方法清除最低位的 1
    while (n) {
        count++;
        n &= (n - 1);  // 清除最低位的 '1'
    }
    return count;
}

int main() {
    int num;
    scanf("%d", &num);
    int onesCount = countOnes(num);
    printf("%d\n", onesCount);
    
    return 0;
}
