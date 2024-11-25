#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 用于排序的比较函数
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int dragon_heads[n];
    int warriors[m];
    
    // 读取龙头的直径
    for (int i = 0; i < n; i++) {
        scanf("%d", &dragon_heads[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &warriors[i]);
    }
    
    // 对龙头和勇士进行排序
    qsort(dragon_heads, n, sizeof(int), compare);
    qsort(warriors, m, sizeof(int), compare);
    

    int total_cost = 0;
    bool used_warriors[m]; 
    for (int i = 0; i < m; i++) {
        used_warriors[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        int min_cost = -1;
        int chosen_warrior_index = -1;
        
        // 找到可用的勇士中身高最小的
        for (int j = 0; j < m; j++) {
            if (!used_warriors[j] && warriors[j] >= dragon_heads[i]) {
                if (min_cost == -1 || warriors[j] < min_cost) {
                    min_cost = warriors[j];
                    chosen_warrior_index = j;
                }
            }
        }
        
        if (chosen_warrior_index == -1) {  // 没有可用的勇士
            printf("bit is doomed!\n");
            return 0;
        }
        
        // 使用这个勇士
        used_warriors[chosen_warrior_index] = true;
        total_cost += min_cost;
    }

    printf("%d\n", total_cost);
    return 0;
}
