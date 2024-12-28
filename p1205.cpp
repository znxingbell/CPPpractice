#include <iostream>
using namespace std;
int main(){
    int num;
    static bool a[15][15]={0},b[15][15]={0},unable[10]={0},deter[5]={0};
    char temp;
    cin>>num;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            cin>>temp;
            if(temp=='@'){
                a[i][j]=1;
            }
        }
    }
    for(int m=1;m<=num;m++){
        for(int n=1;n<=num;n++){
            cin>>temp;
            if(temp=='@'){
                b[m][n]=1;
            }
        }
    }
    for(int x=1;x<=num;x++){
        for(int y=1;y<=num;y++){
            if(a[x][y]!=b[y][num-x+1]){
                unable[1]=true;
            }
            if(a[x][y]!=b[num-x+1][num-y+1]){
                unable[2]=true;
            }
            if(a[x][y]!=b[num-y+1][x]){
                unable[3]=true;
            }
            if(a[x][y]!=b[x][num-y+1]){
                unable[4]=true;
            }
            if(a[x][y]!=b[num-y+1][num-(x)+1]){
                deter[1]=true;
            }
             if(a[x][y]!=b[num-(x)+1][num-(num-y+1)+1]){
                deter[2]=true;
            }
             if(a[x][y]!=b[num-(num-y+1)+1][x]){
                deter[3]=true;
            }
            if(deter[1]==true&&deter[2]==true&&deter[3]==true){
                unable[5]=true;      
            }
            if(a[x][y]!=b[x][y]){
                unable[6]=true;
            }          
        }
    }
    for(int k=1;k<=6;k++){
        if(unable[k]==false){
            cout<<k;
            return 0;
        }
    }
    cout<<"7";
    return 0;
}