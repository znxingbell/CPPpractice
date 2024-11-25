#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int map1[N][N], map2[N][N];
int visited1[N][N]={0}, visited2[N][N]={0};
int path1[N][N]={0}, path2[N][N]={0};
int ans[N][N]={0};

typedef struct {
    int x, y, layer;
} Node;
Node queue[2 * N * N];
int front = 0, rear = 0;
void enqueue(int x, int y, int layer, int surround_x, int surround_y) {
    if(layer == 1){
        visited1[surround_x][surround_y] = 1;
        path1[surround_x][surround_y] = x * N + y;
    }else{
        visited2[surround_x][surround_y] = 1;
        path2[surround_x][surround_y] = x * N + y;
    }
    queue[rear].x = surround_x;
    queue[rear].y = surround_y;
    queue[rear].layer = layer;
    rear++;
}
Node dequeue() {
    return queue[front++];
}
void print(int start_x, int start_y, int end_x, int end_y){
    int x = end_x;
    int y = end_y;
    int layer = 2, temp;
    ans[x][y] = 223;
    while(x != start_x || y != start_y){
        if(layer == 2){
            if(x == path2[x][y] / N && y == path2[x][y] % N){
                layer = 1;
                ans[x][y] = 10;
                continue;
            }
            temp = x;
            x = path2[x][y] / N;
            y = path2[temp][y] % N;
            ans[x][y] = 2;
        }else{
            if(x == path1[x][y] / N && y == path1[x][y] % N){
                layer = 2;
                ans[x][y] = 10;
                continue;
            }
            temp = x;
            x = path1[x][y] / N;
            y = path1[temp][y] % N;
            if(ans[x][y] == 2){
                ans[x][y] = 12;
            }else{
                ans[x][y] = 1;
            }
        }
    }
    ans[x][y] = 7;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ans[i][j] == 223) {
                printf("  xx");
            } else if (ans[i][j] == 10) {
                    printf("   +");
            } else {
                    printf("%4d", ans[i][j]);
            }
        }
        printf("\n");
    }
}
int enable(int x, int y, int layer){
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 0;
    }
    if (layer == 1) {
        if (visited1[x][y] == 1 || map1[x][y] == 0) {
            return 0;
        }
    } else {
        if (visited2[x][y] == 1 || map2[x][y] == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &map2[i][j]);
            if (map2[i][j] == 223) {
                end_x = i;
                end_y = j;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &map1[i][j]);
            if (map1[i][j] == 7) {
                start_x = i;
                start_y = j;
                visited1[i][j] = 1;
                enqueue(i, j, 1, i, j);
            }
        }
    }
    while(front < rear){
        Node current = dequeue();
        int x = current.x;
        int y = current.y;
        int layer = current.layer;
        for(int i = 0; i < 4; i++){
            int surround_x = x + (i >> 1)*(i & 1?1:-1);
            int surround_y = y + !(i >> 1)*(i & 1?1:-1);
            if (enable(surround_x, surround_y, layer)) {
                enqueue(x, y, layer, surround_x, surround_y);
                if (enable(surround_x, surround_y, 3 - layer) && map1[surround_x][surround_y] == 2) {
                    enqueue(surround_x, surround_y, 3 - layer, surround_x, surround_y);
                }
                if (surround_x == end_x && surround_y == end_y && layer == 2) {
                    print(start_x, start_y, end_x, end_y);
                    return 0;
                }
            }
        }
    }
    printf("世上本没有路......\n");
}