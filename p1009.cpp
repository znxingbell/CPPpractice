#include<stdio.h>
int m,n,y;
int a[100],b[100],c[100],d[100],e[100];
//a为阶乘函数结果b,e为进位使用c为输出结果d为临时结果
void times(int k)//阶乘计算函数
{
    d[1]=a[1]*k%10;
    b[2]=a[1]*k/10%10+a[2]*k%10;
    d[2]=b[2]%10;
    for(int i=3;i<=100;i++)
    {
        b[i]=a[i]*k%10+a[i-1]*k/10%10+a[i-2]*k/100+b[i-1]/10;
        d[i]=b[i]%10;
    }
    for(int j=1;j<=100;j++)
        a[j]=d[j];
}

int main()
{
    a[1]=1;
    scanf("%d",&n);
    for(m=1;m<=n;m++)//累加
    {
        times(m);
        e[1]=c[1]+a[1];
        c[1]=e[1]%10;
        for(int l=2;l<=100;l++)
        {
            e[l]=(c[l]+a[l])+e[l-1]/10;
            c[l]=e[l]%10;
        }
    }
    for(y=100;c[y]==0;y--);
    for(int x=y;x>=1;x--)
    {
            printf("%d",c[x]);
    }
    printf("\n");
}