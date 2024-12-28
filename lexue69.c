#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    int lineNumber;
    
    // 读取文件名和行号
    scanf("%s", filename);
    scanf("%d", &lineNumber);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File Name Error.\n");
        return 1;
    }

    char line[256];
    int currentLine = 1;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (currentLine == lineNumber) {
            printf("%s", line);
            found = 1;
            break;
        }
        currentLine++;
    }

    if (!found) {
        printf("Line No Error.\n");
    }

    fclose(file);
    return 0;
}