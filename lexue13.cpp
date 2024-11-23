#include <stdio.h>
#include <stdlib.h>
int year,month,day,w,c,y;
void determine(int i,int j){
   if(day<i||day>j){
      printf("day is wrong.\n");
      exit(0);
   }
}
int main(){
   scanf("%d%d%d",&year,&month,&day);
   switch(month){
      case 1 : determine(1,31); break;
      case 2 : determine(1,year%4==0 && year%100!=0 || year%400==0?29:28); break;
      case 3 : determine(1,31); break;
      case 4 : determine(1,30); break;
      case 5 : determine(1,31); break;
      case 6 : determine(1,30); break;
      case 7 : determine(1,31); break;
      case 8 : determine(1,31); break;
      case 9 : determine(1,30); break;
      case 10 : determine(1,31); break;
      case 11: determine(1,30); break;
      case 12 : determine(1,31); break;
      default : if(day<1||day>31)
                  printf("month and day are wrong.\n");
                else
                  printf("month is wrong.\n"); 
                return 0;
   }
   if(month < 3){
      month = month+12;
      year = year-1;
   }
   c = year/100;
   y = year%100;
   w = (y+y/4+c/4-2*c+26*(month+1)/10+day)%7;
   w = (w+6)%7;
   printf("%d\n",w);
}
