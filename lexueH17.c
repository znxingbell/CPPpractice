/*
    一天，小星在文萃M223上完程设课着急回甘棠园，却忘了路。于是他找程设老师要了地图。请你设计一个导航程序，在地图范围内找出小星回甘棠园的路线。

一、输入

    如示例所示，输入共二十一行。前十行和后十行均为10*10的矩阵，分别表示二层地图和一层地图。第十一行什么也没有，便于查看而已。

    典型数据请参见公开的测试用例。其中，0表示障碍物，1表示可通行区域，2表示楼梯（可往返一、二层，且属于可通行区域），7表示甘棠园入口，223表示M223。

二、数据范围

    甘棠园入口唯一且在一层、M223唯一且在二层，甘棠园和M223坐标不相同，楼梯不超过三个且一、二层对应楼梯坐标相同。

程设老师看出了小星的迫切，已帮他排除了全部劣解，即小星回甘棠园的路线至多一条。

注：地图如与现实雷同，纯属巧合。

三、输出

    路线连接M223与甘棠园，既不重复，也不斜行。

    若有解，如示例所示，输出一个10*10的矩阵，表示路线。其中，在一、二层的路线分别用1、2表示，重叠不交汇处用12表示，交汇处用+表示。最后将M223用xx（小星）覆盖，甘棠园位置用7覆盖，其余均用0表示。
    若无解，输出“世上本没有路......\n”。

四、提示

    1、本题或用到标准库（stdlib.h）头文件的exit函数，它可用于在辅助函数中结束程序；
    2、本题无需使用堆栈等“高级”的数据结构，一、二维数组即可。
*/
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

void enqueue(int x, int y, int layer, int prev_x, int prev_y) {
    if(layer == 1){
        visited1[x][y] = 1;
        path1[x][y] = prev_x * N + prev_y;
    }else{
        visited2[x][y] = 1;
        path2[x][y] = prev_x * N + prev_y;
    }
    queue[rear].x = x;
    queue[rear].y = y;
    queue[rear].layer = layer;
    rear++;
}

Node dequeue() {
    return queue[front++];
}

void print(int start_x, int start_y, int end_x, int end_y){
    int x = end_x;
    int y = end_y;
    int layer = 2;
    ans[x][y] = -2; // 终点标记为 -2

    while(!(x == start_x && y == start_y && layer == 1)){
        if(layer == 2){
            int prev = path2[x][y];
            int prev_x = prev / N;
            int prev_y = prev % N;
            if(prev_x == x && prev_y == y){
                layer = 1;
                ans[x][y] = -1; // 楼梯位置标记为 -1
            }else{
                if(ans[x][y] == 0)
                    ans[x][y] = 2; // 二层路径
            }
            x = prev_x;
            y = prev_y;
        }else{
            int prev = path1[x][y];
            int prev_x = prev / N;
            int prev_y = prev % N;
            if(prev_x == x && prev_y == y){
                layer = 2;
                ans[x][y] = -1; // 楼梯位置标记为 -1
            }else{
                if(ans[x][y] == 2){
                    ans[x][y] = 12; // 重叠路径
                }else{
                    if(ans[x][y] == 0)
                        ans[x][y] = 1; // 一层路径
                }
            }
            x = prev_x;
            y = prev_y;
        }
    }
    ans[start_x][start_y] = 7; // 起点标记为 7

    // 输出结果，使用 '+' 标记楼梯位置，'xx' 标记终点
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ans[i][j] == -2) {
                printf("  xx");
            } else if (ans[i][j] == -1) {
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
    // 读取二层地图
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &map2[i][j]);
            if (map2[i][j] == 223) {
                end_x = i;
                end_y = j;
            }
        }
    }
    // 读取一层地图
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &map1[i][j]);
            if (map1[i][j] == 7) {
                start_x = i;
                start_y = j;
            }
        }
    }
    enqueue(start_x, start_y, 1, start_x, start_y);
    visited1[start_x][start_y] = 1;

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 上下左右方向

    while(front < rear){
        Node current = dequeue();
        int x = current.x;
        int y = current.y;
        int layer = current.layer;
        if(x == end_x && y == end_y && layer == 2){
            print(start_x, start_y, end_x, end_y);
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int surround_x = x + dir[i][0];
            int surround_y = y + dir[i][1];
            if (enable(surround_x, surround_y, layer)) {
                enqueue(surround_x, surround_y, layer, x, y);
                if ((layer ==1 && map1[surround_x][surround_y] ==2) || (layer ==2 && map2[surround_x][surround_y]==2)){
                    if (enable(surround_x, surround_y, 3 - layer)){
                        enqueue(surround_x, surround_y, 3 - layer, surround_x, surround_y);
                    }
                }
            }
        }
    }
    printf("世上本没有路......\n");
    return 0;
}