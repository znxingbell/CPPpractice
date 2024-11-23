#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a=n%10;
    int b=n/10;
    switch(n){
        case 10 : printf("Ten\n"); return 0;
        case 11 : printf("Eleven\n"); return 0;
        case 12 : printf("Twelve\n"); return 0;
        case 13 : printf("Thirteen\n"); return 0;
        case 14 : printf("Fourteen\n"); return 0;
        case 15 : printf("Fifteen\n"); return 0;
        case 16 : printf("Sixteen\n"); return 0;
        case 17 : printf("Seventeen\n"); return 0;
        case 18 : printf("Eighteen\n"); return 0;
        case 19 : printf("Nineteen\n"); return 0;
        case 20 : printf("Twenty\n"); return 0;
        case 30 : printf("Thirty\n"); return 0;
        case 40 : printf("Forty\n"); return 0;
        case 50 : printf("Fifty\n"); return 0;
        case 60 : printf("Sixty\n"); return 0;
        case 70 : printf("Seventy\n"); return 0;
        case 80 : printf("Eighty\n"); return 0;
        case 90 : printf("Ninety\n"); return 0;
    }
    switch(b){
        case 2 : printf("Twenty"); break;
        case 3 : printf("Thirty"); break;
        case 4 : printf("Forty"); break;
        case 5 : printf("Fifty"); break;
        case 6 : printf("Sixty"); break;
        case 7 : printf("Seventy"); break;
        case 8 : printf("Eighty"); break;
        case 9 : printf("Ninety"); break;
    }
    printf("-");
    switch(a){
        case 1 : printf("one\n"); return 0;
        case 2 : printf("two\n"); return 0;
        case 3 : printf("three\n"); return 0;
        case 4 : printf("four\n"); return 0;
        case 5 : printf("five\n"); return 0;
        case 6 : printf("six\n"); return 0;
        case 7 : printf("seven\n"); return 0;
        case 8 : printf("eight\n"); return 0;
        case 9 : printf("nine\n"); return 0;
    }
}