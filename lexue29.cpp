#include <stdio.h>
#include <ctype.h>
void print_blank(int x){
    for(int y=1;y<=x;y++){
        printf(" ");
    }
}
int main(){
    int n;
    char c,ans;
    scanf("%d %c",&n,&c);
    if(!isupper(c)){
        printf("input error.\n");
        return;
    }
    for(int m=n;m>=2;m--){
        ans=c+m-1;
        if(ans>'Z'){
            ans='A'+(ans-'Z'-1)%26;
        }
        print_blank(n-m);
        printf("%c",ans);
        print_blank((m-1)*2-1);
        printf("%c\n",ans);
        }
    print_blank(n-1);
    printf("%c\n",c); 
    for(int m=2;m<=n;m++){
        ans=c+1-m;
        if(ans<'A'){
            ans='Z'-('A'-ans-1)%26;
        }
        print_blank(n-m);
        printf("%c",ans);
        print_blank((m-1)*2-1);
        printf("%c\n",ans);
        }

}