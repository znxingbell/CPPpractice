#include <stdio.h>
#include <ctype.h>
int main(){
    int n;
    int c,ans,ans2;
    scanf("%d %c",&n,&c);
    c=toupper(c);
    if(!isupper(c)){
        printf("Input error!\n");
        return 0;
    }
    if(n==1){
        printf("%c\n",c);
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans=c+i-1;
        if(ans>'Z'){
            ans='A'+(ans-'Z'-1)%26;
        }
        printf("%c",ans);
        if(i!=n){
            printf(" ");
        }else{
            printf("\n");
        }
    }
	ans=c;
    for(int j=1;j<=n-2;j++){
        ans++;
        if(ans>'Z'){
            ans-=26;
        }
        printf("%c",ans);
        for(int y=1;y<=2*(n-2)+1;y++){
            printf(" ");
        }
        ans2=ans+(n-1);
        if(ans2>'Z'){
            ans2-=26;
        }
        printf("%c\n",ans2);
    }
	ans=c+n-2;
    for(int i=1;i<=n;i++){
		ans++;     
        if(ans>'Z'){
            ans-=26;
        }
        printf("%c",ans);
        if(i!=n){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}
/*
# include<stdio.h>
int main()
{
	int n, r, l;
	char c;
	scanf("%d %c", &n, &c);
	if((('z'>= c && 'a'<= c)||('Z'>=c&&'A'<=c))&&(n > 1))
	{
		if(('z'>= c && 'a'<= c))
		{
			c=c+'A'-'a';
		}
		l = c;
		for(int i=0;i<n;i++)
		{
			if(i<n-1)
			{
				printf("%c ", l);
			}
			else
				printf("%c", l);
			l ++;
			if(l > 'Z')
				l = 'A';
		}
		r = l;
		printf("\n");
		l = c + 1;
		for(int i=0;i<n-2;i++)
		{
			if(l > 'Z')
				l = 'A';
			if(r > 'Z')
				r = 'A';
			printf("%c ", l);
			l ++;
			for(int j=0;j<n-2;j++)
			{
				printf("  ");
			}
			printf("%c\n", r);
			r ++;
		}
		for(int i=0;i<n;i++)
		{
			if(l > 'Z')
				l = 'A';
			if(i<n-1)
			{
				printf("%c ", l);
			}
			else
				printf("%c", l);
			
			l ++;
		
		}
		printf("\n");
	}
	else if((('z'>= c && 'a'<= c)||('Z'>=c&&'A'<=c))&&(n = 1))
	{
		if(('z'>= c && 'a'<= c))
		{
			c=c+'A'-'a';
		}
		printf("%c\n", c);
	}
	else
	{
		printf("Input error!\n");
	}
	return 0;
}
*/