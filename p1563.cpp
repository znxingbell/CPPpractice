#include <iostream>
#define MAX 100000
using namespace std;
int main(){
    int n, m,direction,step,j=0;
    cin >> n >> m;
    int face[MAX];
    char type[MAX][11];
    for(int i=0;i<n;i++)
        cin >> face[i] >> type[i];
    for(int i=0;i<m;i++){
        cin >> direction >> step;
        if(direction ^ face[j]){
            j += step;
            if(j >= n)
                j -= n;
        }else{
            j -= step;
            if(j < 0)
                j += n;
        }
    }
    cout << type[j] << endl;
}