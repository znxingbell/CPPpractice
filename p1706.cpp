 #include <stdio.h>
 int n,out[10];
 bool used[10];

 void blank(int k)
 {
    if(k==n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%5d",out[i]);
        }
        printf("\n");
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if(used[j]==0)
        {
            used[j]=1;
            out[k+1]=j;
            blank(k+1);
            used[j]=0;
        }

    }
 }
 
 int main()
 {

    scanf("%d",&n);
    blank(0);
    return 0;
 }
 