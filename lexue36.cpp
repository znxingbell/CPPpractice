#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int found = 0; 

    // 遍历每一行
    for (int i = 0; i < n; i++) {
        int max_val = arr[i][0];
        int col_index = 0;

        // 找到当前行的最大值及其列索引
        for (int j = 1; j < m; j++) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
                col_index = j;
            }
        }

        // 检查该最大值是否是其所在列的最小值
        int is_saddle_point = 1; 
        
        for (int k = 0; k < n; k++) {
            if (arr[k][col_index] < max_val) {
                is_saddle_point = 0; 
                break;
            }
        }

        if (is_saddle_point) {
            printf("Point:a[%d][%d]==%d\n", i, col_index, max_val);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("No Point\n");
    }

    return 0;
}
