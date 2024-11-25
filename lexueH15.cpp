#include <stdio.h>
int num[]={-50, -2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40};
int score(int n){
    char x[16];
    int y[16], count = 0, flag[3] = {0}, point = 0;
    for(int i = 0; i < n; i++){
        scanf(" %c%d", &x[i], &y[i]);
        if(x[i] == 'H'){
            count++;
            point += num[y[i] - 1];
        }
        if(x[i] == 'C' && y[i] == 10){
            flag[0] = 1;
        }
        if(x[i] == 'S' && y[i] == 12){
            flag[1] = 1;
        }
        if(x[i] == 'D' && y[i] == 11){
            flag[2] = 1;
        }
    }
    if(count == 13){
        if(flag[1]==1&&flag[2]==1){
            point = 500;
        }else{
            point = 200;
        }
    }
    if(flag[1]==1&&flag[2]==0){
        point -= 100;
    }
    if(flag[1]==0&&flag[2]==1){
        point += 100;
    }
    if(flag[0]==1){
        if(n == 1){
            point = 50;
        }else{
            point *= 2;
        }
    }
    return point;
}
int main(){
    int num[4], ans[4];
    while(1){
        for(int i = 0; i < 4; i++){
            scanf("%d", &num[i]);
            ans[i] = score(num[i]);
        }
        if(num[0] == 0 && num[1] == 0 && num[2] == 0 && num[3] == 0){
            break;
        }
        for(int i = 0; i < 4; i++){
            if (ans[i] == 0) {
                printf("0");
            } else {
                printf("%+d", ans[i]);
            }
            if(i != 3){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    return 0;
}