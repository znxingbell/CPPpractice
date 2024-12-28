#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1001

void input(char *p){
    fgets(p,MAX+11,stdin);
    p[strcspn(p, "\n")] = '\0';
    while(*p){  
        *p=tolower(*p);
        p++;
    }
}

int main(){
    int counter=0,first,flag=0,time=0;
	char word[11]={0},paper[MAX]={0};
	input(word);
    input(paper);
    size_t length=strlen(word);
    char *result = strstr(paper, word),*present;
    while(result){
        if((*(result+length)==' '||*(result+length)=='\000')&&(*(result-1)==' '||first==0)){
            if(time==0){
                first = result - paper;
                time=1;
            }
            counter++;
            flag=1;
        }
         present = result + length;
         result = strstr(present, word);
    }
    if(flag){
        printf("%d %d\n",counter,first);
    }else{
        printf("-1");
    }
	return 0;

}