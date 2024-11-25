#include <stdio.h>

int main() {
    int scores[10]; 
    int maxScore = 0; 
    int count = 0; 
    int i, j;
    for (i = 0; i < 10; i++) {
        scanf("%d", &scores[i]);
        if (scores[i] > maxScore) {
            maxScore = scores[i]; 
            count = 1; 
        } else if (scores[i] == maxScore) {
            count++; 
        }
    }
    for (i = 0; i < 10; i++) {
        if (scores[i] == maxScore) {
            printf("%d\n", i + 1); 
        }
    }
    return 0;
}