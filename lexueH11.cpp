#include <stdio.h>

#define MAX_SIZE 100 

void rotate90Clockwise(int n, int arr[MAX_SIZE][MAX_SIZE]) {
    int rotated[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[n - 1 - j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rotated[i][j];
        }
    }
}

void printArray(int n, int arr[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", arr[i][j]);
            if(j!=n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n = 6;
    int arr[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    rotate90Clockwise(n, arr);
    printArray(n, arr);

    return 0;
}
