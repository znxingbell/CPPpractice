#include <stdio.h>
int main(){
    int start,present;
    scanf("%c",&start);
    for(int i=0;i<=25;i++){
        present=start+i;
        if(start<95&&present>90){
            present=64+(present-90)%26;
        }
        if(start>95&&present>122){
            present=96+(present-122)%26;
        }
        printf("%c",present);
    }
    printf("\n");

}