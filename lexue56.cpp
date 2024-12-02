#include <stdio.h>
#include <string.h>

int main() {
    static char s[1000], t[100], str[100], temp[1000];
    
    // 使用 fgets 代替 gets 以避免缓冲区溢出
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);
    fgets(str, sizeof(str), stdin);
    
    // 去掉 fgets 读取的换行符
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';
    str[strcspn(str, "\n")] = '\0';

    char *p = s;
    while ((p = strstr(p, t)) != NULL) {
        // 计算替换的位置
        int pos = p - s;
        s[pos] = '\0';
        
        // 构建新的字符串
        strcpy(temp, s);
        strcat(temp, str);
        strcat(temp, p + strlen(t));
        
        // 更新原始字符串
        strcpy(s, temp);
        
        // 移动指针以继续查找
        p = s + pos + strlen(str);
    }
    
    puts(s);
    return 0;
}