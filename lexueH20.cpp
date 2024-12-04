/*
对于非常大或者非常小的数据，我们通常用科学记数法来表示。例如在科技文献和电脑中经常遇到的 2.3×106 （计算机中的科学记数法表示为：2.3E6），或者 9.18×10-5 （科学记树法表示：9.18E-5）这种类型的数据。

输入：
    用科学记数法表示的数据。即为符合C语言表示的科学记数法表示。

输出：
    该数据的双精度表示

说明：
    输入数据的精度不高于小数点后50位。
    输入数据时，在实数和幂之间有空格进行分隔，空格个数不定。
    结果保留到小数点后8位，如不足8位用0补足，超过8位则截断，不进行四舍五入的处理。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[300], num[100], exp_str[20];
    fgets(input, sizeof(input), stdin);

    // 去除输入中的空格和换行符
    char temp[300];
    int idx = 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] != ' ' && input[i] != '\n')
            temp[idx++] = input[i];
    }
    temp[idx] = '\0';

    // 查找'E'或'e'的位置
    char *e_pos = strchr(temp, 'E');
    if (!e_pos)
        e_pos = strchr(temp, 'e');
    if (!e_pos) {
        printf("Invalid input\n");
        return 0;
    }

    // 分离实数和指数部分
    *e_pos = '\0';
    strcpy(num, temp);
    strcpy(exp_str, e_pos + 1);

    // 处理指数部分
    int exp = atoi(exp_str);

    // 检查是否为负数
    int is_negative = 0;
    int start_idx = 0;
    if (num[0] == '-') {
        is_negative = 1;
        start_idx = 1; // 从下一个字符开始处理
    }

    // 去掉小数点，记录小数点位置
    char digits[100];
    int dot_pos = -1, len = 0;
    for (int i = start_idx; num[i]; i++) {
        if (num[i] == '.') {
            dot_pos = i - start_idx;
        } else {
            digits[len++] = num[i];
        }
    }
    digits[len] = '\0';

    // 计算小数点应移的位置
    int total_exp;
    if (dot_pos == -1)
        total_exp = len;
    else
        total_exp = dot_pos;

    total_exp += exp;

    // 构建结果字符串
    char result[500];
    int result_len = 0;

    if (is_negative)
        result[result_len++] = '-';

    if (total_exp <= 0) {
        result[result_len++] = '0';
        result[result_len++] = '.';
        for (int i = 0; i < -total_exp; i++)
            result[result_len++] = '0';
        for (int i = 0; i < len; i++)
            result[result_len++] = digits[i];
    } else {
        int has_dot = 0; // 是否已经添加了小数点
        for (int i = 0; i < len; i++) {
            result[result_len++] = digits[i];
            if (i + 1 == total_exp && i + 1 < len) {
                result[result_len++] = '.';
                has_dot = 1;
            }
        }
        if (total_exp < len && !has_dot) {
            result[result_len++] = '.';
            has_dot = 1;
        }
        if (total_exp > len) {
            for (int i = 0; i < total_exp - len; i++)
                result[result_len++] = '0';
        }
    }
    result[result_len] = '\0';

    // 去除结果中的多余前导零
    idx = is_negative ? 1 : 0;
    while (result[idx] == '0' && result[idx + 1] != '.' && result[idx + 1] != '\0')
        idx++;

    // 处理小数点后8位
    char final_result[500];
    int final_len = 0;

    if (is_negative)
        final_result[final_len++] = '-';

    strcpy(final_result + final_len, result + idx);
    final_len = strlen(final_result);

    char *dot_ptr = strchr(final_result, '.');
    if (!dot_ptr) {
        strcat(final_result, ".00000000");
    } else {
        int decimal_len = strlen(dot_ptr + 1);
        if (decimal_len > 8) {
            dot_ptr[9] = '\0'; // 截断，不进行四舍五入
        } else if (decimal_len < 8) {
            for (int i = 0; i < 8 - decimal_len; i++)
                strcat(final_result, "0");
        }
    }

    printf("%s\n", final_result);

    return 0;
}
