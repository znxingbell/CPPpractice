#include <stdio.h>

int n;
int counter = 0;
int columns[20] = {0};
int diag1[20] = {0};
int diag2[20] = {0};

void backtrack(int row){
    if(row == n){
        counter++;
        return;
    }
    for(int col = 0; col < n; col++){
        int d1 = row + col;
        int d2 = row - col + n - 1;
        if(!columns[col] && !diag1[d1] && !diag2[d2]){
            columns[col] = diag1[d1] = diag2[d2] = 1;
            backtrack(row + 1);
            columns[col] = diag1[d1] = diag2[d2] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    backtrack(0);
    printf("%d\n", counter);
    return 0;
}