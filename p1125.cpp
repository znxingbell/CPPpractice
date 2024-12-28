#include <stdio.h>
#include <string.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1; 
    if (num % 2 == 0) return 0; 
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1;
}

int main(){
    char word[110];
    int count[30]={0},max_count=1,min_count=100,sub;
    fgets(word,sizeof(word),stdin);
    word[strcspn(word, "\n")] = '\0';
    const char *p=word; 
    while(*p){
        count[*p-'a']++;
        p++;
    }
    for(int i=0;i<26;i++){
        if(count[i]>max_count){
            max_count=count[i];
        }
        if(count[i]<min_count&&count[i]!=0){
            min_count=count[i];
        }
    }
    sub=max_count-min_count;
    if(is_prime(sub)){
        printf("Lucky Word\n%d\n",sub);
    }else{
        printf("No Answer\n0\n");
    }
    return 0;
}
/*
#include <stdio.h>
#include <string.h>

void find_most_frequent_char(const char *str) {
    int count[26] = {0}; // 假设只处理小写字母
    int max_count = 0; // 最大出现次数
    char most_frequent_char = '\0'; // 最常出现的字符

    // 统计每个字符的出现次数
    while (*str) {
        if (*str >= 'a' && *str <= 'z') { // 只处理小写字母
            count[*str - 'a']++; // 计算字母出现的次数
        }
        str++;
    }

    // 找出出现次数最多的字母
    for (int i = 0; i < 26; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            most_frequent_char = 'a' + i; // 将索引转换回字母
        }
    }

    if (max_count > 0) {
        printf("出现次数最多的字符是 '%c'，出现了 %d 次\n", most_frequent_char, max_count);
    } else {
        printf("字符串中没有小写字母\n");
    }
}

int main() {
    char str[100]; // 存储输入字符串
    printf("请输入字符串: ");
    fgets(str, sizeof(str), stdin); // 安全读取字符串

    // 去除换行符（如果有的话）
    str[strcspn(str, "\n")] = '\0';

    find_most_frequent_char(str); // 查找出现次数最多的字符

    return 0;
}
*/