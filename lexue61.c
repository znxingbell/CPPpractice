#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int score;
    char name[21];
} student;

int cmp(const void *a, const void *b) {
    return ((student *)b)->score - ((student *)a)->score;
}

int main() {
    int n;
    scanf("%d", &n);
    student *s = (student *)malloc(n * sizeof(student));
    for (int i = 0; i < n; i++){
        getchar();
        scanf("%20[^,],%d", s[i].name, &s[i].score);
    }
    qsort(s, n, sizeof(student), cmp);
    for (int i = 0; i < n; i++)
        printf("%s,%d\n", s[i].name, s[i].score);
    free(s);
    return 0;
}