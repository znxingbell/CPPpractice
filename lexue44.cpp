#include <stdio.h>
int main() {
    int n, m, count, time = 1;
    char arr[110][110] = {0};

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
        if (time != 1) {
            printf("\n");
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf(" %c", &arr[i][j]);
            }
        }
        printf("Field #%d:\n", time);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == '*') {
                    printf("%c", arr[i][j]);
                } else {
                    count = 0;
                    for (int x = i - 1; x <= i + 1; x++) {
                        for (int y = j - 1; y <= j + 1; y++) {
                            if (x > 0 && x <= n && y > 0 && y <= m && arr[x][y] == '*') {
                                count++;
                            }
                        }
                    }
                    printf("%d", count);
                }
            }
            printf("\n");
        }
        time++;
    }
    return 0;
}