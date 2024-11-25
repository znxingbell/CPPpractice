#include <stdio.h>
#include <math.h>
int n;
static int a[20]={0},b[20];
long long sum=0;

long long last(int x) //获取当前数的后x位
{
    long long y=0;
    for(int i=1;i<=x;i++)
    {
        y+=a[i]*pow(10,i-1);
    }
    return y;
}

void blank(int z) //查找倒数z格
{
    int precise=z/3;//精度修正数
    if(z>n)//查找完毕
        return;
    for(int j=0;j<=9;j++)
    {
        a[z]=j;
        for(int k=1;k<=z;k++)//求后z位积的首位
            sum+=last(k)*a[z+1-k]*pow(10,(z-k))/pow(10,z-2-precise);
        sum=(sum/pow(10,precise+1));//防数据溢出处理
        sum=sum%10;
        if(sum==j)
        {
            blank(z+1);//进入下一位搜索
            return;
        }
        sum=0;
    }
    a[z]=0;
    blank(z+1);
}
 int main()
 {
    scanf("%d",&n);
    if(n==1)//特殊值
    {
        printf("1\n5\n6\n");
        return 0;
    }
    a[1]=5;//末位为5的系列数
    blank(2);
    for(int m=n;m>=1;m--)
        b[m]=a[m];
    a[1]=6;//末位为6的系列数
    blank(2);
    if(b[n]>a[n])//从小到大输出
    {
        if(a[n]!=0)
        {
            for(int l=n;l>=1;l--)
                printf("%d",a[l]);
            printf("\n");
            for(int l=n;l>=1;l--)
                printf("%d",b[l]);
            printf("\n");
        }
        else
        {
            for(int l=n;l>=1;l--)
                printf("%d",b[l]);
            printf("\n");
        }
    }
    else
    {
        if(b[n]!=0)
        {
            for(int l=n;l>=1;l--)
                    printf("%d",b[l]);
                printf("\n");
            for(int l=n;l>=1;l--)
                    printf("%d",a[l]);
                printf("\n");
        }
        else
        {
            for(int l=n;l>=1;l--)
                    printf("%d",a[l]);
                printf("\n");
        }
    }
    return 0;
 }