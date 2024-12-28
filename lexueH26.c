#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    if (scanf("%d %d", &m, &n) != 2) {
        printf("输入格式错误\n");
        return 1;
    }
    
    char grid[m][n];
    
    // 读取m行n列的0和1
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            if (scanf(" %c", &c) != 1) {
                printf("输入格式错误\n");
                return 1;
            }
            if (c != '0' && c != '1') {
                printf("输入必须是0或1\n");
                return 1;
            }
            grid[i][j] = c;
        }
    }
    
    // 计算每行的1的个数
    int row_mismatches = 0;
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
            }
        }
        if (count % 2 != 0) {
            row_mismatches++;
        }
    }
    
    // 计算每列的1的个数
    int col_mismatches = 0;
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (grid[i][j] == '1') {
                count++;
            }
        }
        if (count % 2 != 0) {
            col_mismatches++;
        }
    }
    
    // 计算最少出错的位数
    int min_errors = 0;
    if (row_mismatches == 0 && col_mismatches == 0) {
        min_errors = 0;
    }
    else if (row_mismatches == 1 && col_mismatches == 1) {
        min_errors = 1;
    }
    else {
        min_errors = max(row_mismatches, col_mismatches);
    }
    
    printf("%d\n", min_errors);
    
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}