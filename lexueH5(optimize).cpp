#include<stdio.h>
int main()
{
	long long fz,fm,a,b;
	__int128 FZ=1,FM=1,A,B,x,y,temp;
    int n,i=1;
	scanf  ("%d",&n);
	for (i=1;i<=n;i++)
	    {
	   	 scanf ("%lld %lld",&a,&b);
		 A=a;
		 B=b;
	   	 FZ=A*FZ;FM=B*FM;
			x=FZ>FM?FZ:FM;
			y=FZ>FM?FM:FZ;
			    while (y!=0)
			        {
				       temp=x%y;
					   x=y; 
					   y=temp;
		         	}
		    FZ=FZ/x;
		    FM=FM/x;
		}
		fz=FZ;
		fm=FM;
	if (fm==1)
	   {
	   	printf("%lld\n",fz);
	   }
	else
	printf("%lld/%lld\n",fz,fm);
}