#include <stdio.h>

int main(){
    char num[10][5][4]={
    "XXX",
	"X.X",
	"X.X",
	"X.X",
	"XXX",
    "..X",
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",
	"..X",
	"XXX",
	"X..",
	"XXX",
	"XXX",
	"..X",
	"XXX",
	"..X",
	"XXX",
	"X.X",
	"X.X",
	"XXX",
	"..X",
	"..X",
	"XXX",
	"X..",
	"XXX",
	"..X",
	"XXX",
	"XXX",
	"X..",
	"XXX",
	"X.X",
	"XXX",
	"XXX",
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",
	"X.X",
	"XXX",
	"X.X",
	"XXX",
	"XXX",
	"X.X",
	"XXX",
	"..X",
	"XXX"
    };
    int n,a[101];
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
        scanf("%1d",&a[k]);
    }
    for(int i=1;i<=5;i++){
        printf("%c%c%c",num[a[1]][i-1][0],num[a[1]][i-1][1],num[a[1]][i-1][2]);
        for(int j=2;j<=n;j++){
            printf(".%c%c%c",num[a[j]][i-1][0],num[a[j]][i-1][1],num[a[j]][i-1][2]);
        }
        printf("\n");
    }
}