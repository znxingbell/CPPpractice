#include <stdio.h>
#include <stdlib.h>
 int main(){
    int n, count = 0, max = -1, start, end;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int j=0;j<n;j++){
        if(a[j]>=a[j+1]){
            count++;
        }else{
            if(count>max){
                max = count;
                end = j + 1;
                start = end - count;
            }
            count = 0;
        }
    }
    printf("%d %d\n",start,end);
    return 0;
 }