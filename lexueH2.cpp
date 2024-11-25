#include <stdio.h>
int year,month=5,day=1,w,c,y;
int main(){
   scanf("%d",&year);
   c = year/100;
   y = year%100;
   w = (y+y/4+c/4-2*c+26*(month+1)/10+day)%7;
   w = (w+6)%7;
   int time=7+(7-w)%7+1;
   printf("%d年的母亲节是5月%d日。\n",year,time);
}
