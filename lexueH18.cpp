/*
校长为了打败恶龙准备召集北理工的勇士们来共同抵御恶龙，在这之前勇士们决定集合商讨一下对策。所以他们准备站成一行与校长进行交谈，但是勇士们的每次移动都是要消耗能量的，求求你们帮帮可怜的校长计算一下所要消耗的最少能量是多少。

北理工的N名勇士随机散落在全校。 北理工的勇士的位置由一对（x，y）整数坐标给出。 勇士可以移动 : 每一次移动，一名士兵可以向上，向下，向左或向右移动一个单位（因此，他可以将他的x或y坐标改为1或-1）。

勇士想要进入彼此相邻的水平线（这样他们的最终位置是（x，y），（x + 1，y），......，（x + N-1，y））。 整数x和y，以及沿水平线的勇士的最终顺序是任意的。

目标是最小化将他们排成一竖列所有勇士的总移动次数。

两个或两个以上的勇士绝不能同时占据同一个位置。

输入：
    第一行包含整数N，1 <= N <= 10000，勇士数量。
    以下N行输入包含勇士的初始位置：对于每个i，1 <= i <= N，输入文件的第（i + 1）行包含一对整数x [i]和y [ i]由单个空白字符分隔，表示第i个勇士的坐标，-10000 <= x [i]，y [i] <= 10000。

输出：
    第一行也是唯一一行应该包含使勇士们彼此相邻的水平线的最小移动总数。
*/
#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于 qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 计算中位数
int median(int *v, int n) {
    qsort(v, n, sizeof(int), compare);
    if (n % 2 == 0) {
        return (v[n / 2 - 1] + v[n / 2]) / 2;
    } else {
        return v[n / 2];
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // 对齐 y 坐标
    int y_median = median(y, N);
    int total_moves = 0;
    for (int i = 0; i < N; ++i) {
        total_moves += abs(y[i] - y_median);
    }

    // 排列 x 坐标
    qsort(x, N, sizeof(int), compare);
    int x_median = median(x, N);
    for (int i = 0; i < N; ++i) {
        total_moves += abs(x[i] - (x_median + i - N / 2));
    }

    printf("%d\n", total_moves);

    free(x);
    free(y);

    return 0;
}