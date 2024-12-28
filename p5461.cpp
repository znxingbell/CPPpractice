#include <iostream>
#include <cmath>
using namespace std;
int ans[1026][1026]={0};
void fill(int x,int y,int n){
    if (n == 0) {
        ans[x][y] = 1;
        return;
    }
    fill(x, y + (1 << (n - 1)), n - 1);
    fill(x + (1 << (n - 1)), y, n - 1);
    fill(x + (1 << (n - 1)), y + (1 << (n - 1)), n - 1);
}
int main(){
    int n;
    cin >> n;
    fill(1,1,n);
    for(int i=1;i<=(1 << n);i++){
        for(int j=1;j<=(1 << n);j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}