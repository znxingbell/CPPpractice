#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int to_decimal(const char* number, int base) {
    int decimal_value = 0;
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        char digit = number[i];
        int value;

        // 检查数字或字母并转换为整数值
        if (isdigit(digit)) {
            value = digit - '0';
        } else if (isalpha(digit)) {
            value = toupper(digit) - 'A' + 10; // 字母从A开始
        } else {
            return -1; // 非法字符
        }

        // 合法性检查: 值不能大于当前进制
        if (value >= base) {
            return -1; // 不合法，返回
        }

        // 更新十进制值
        decimal_value = decimal_value * base + value; 
    }

    return decimal_value;
}

int min_base(const char* number) {
    int min = 2;  // 最小有效进制是2
    for (int i = 0; number[i] != '\0'; i++) {
        char digit = number[i];
        int value;

        if (isdigit(digit)) {
            value = digit - '0';
        } else {
            value = toupper(digit) - 'A' + 10;
        }
        if (value + 1 > min) {
            min = value + 1; // 找到最小进制
        }
    }
    return min;
}

void find_matching_base(const char* M, const char* N) {
    int min_base_M = min_base(M);
    int min_base_N = min_base(N);

    for (int base_M = min_base_M; base_M <= 36; base_M++) {
        int decimal_M = to_decimal(M, base_M);
        if (decimal_M == -1) {
            continue; // 如果无效，跳过
        }

        for (int base_N = min_base_N; base_N <= 36; base_N++) {
            int decimal_N = to_decimal(N, base_N);
            if (decimal_N == -1) {
                continue; // 如果无效，跳过
            }

            if (decimal_M == decimal_N) {
                printf("%s (base %d) = %s (base %d)\n", M, base_M, N, base_N);
                return;
            }
        }
    }
    printf("%s is not equal to %s in any base 2..36\n",M,N);
}

int main() {
    char M[20], N[20];
    scanf("%s %s", M, N);
    find_matching_base(M, N);
    return 0;
}
