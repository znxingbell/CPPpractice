#include <stdio.h>
const char base64[] = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";//映射表
int main(){
    char str[75] = {0}, ans[200] = {0};
    unsigned int i=0, sum, n = 0;
    gets(str);
    while(str[i]){
        sum = 0;
        for(int j = 0;j < 3;j++){
            sum += (str[i++] << 8 * (2 - j)); 
        }//读取三个字节并合并为一个数
        for(int k = 0;k < 4;k++){
            ans[n++] = base64[(sum >> (3 - k) * 6) & 0b00111111];
        }//重分为四组并根据对照表存储结果
    }
    while(!str[--i]){
        ans[--n] = '=';
    }//替换无效的A
    puts(ans);
}