#include <stdio.h>  
int weekdays(int year,int month,int day){  
   int w,c,y;  
   if(month < 3){  
      month = month+12;  
      year = year-1;  
   }  
   c = year/100;  
   y = year%100;  
   w = (y+y/4+c/4-2*c+26*(month+1)/10+day)%7;  
   w = (w+6)%7;  
   return w; 
}  

int leap_year( int year )   // 判断闰年或平年  
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;  
}  
  
int year_days(int year)     // 计算一整年的天数  
{   return leap_year( year ) ? 366 : 365;  
}  
  
int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天  
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
      
    if  ( leap_year( year ) && month >2 )  
        day++;  
      
    for ( i=1; i<month; i++ )  
        day += months[i];  
  
    return day;  
}  
 
int main() 
{   
    char ans[5][9]={{"3 and 8."},{"4 and 9."},{"5 and 0."},{"1 and 6."},{"2 and 7."}};
    int year,month,day;
    scanf("%d %d %d",&year,&month,&day);
    int end_days = days(year,month,day); 
    int start_days = days(2012,4,9);
    int delta_days = 0,start_year = 2012;
    while(start_year < year){
        delta_days += year_days(start_year);
        start_year++;
    }
    delta_days += end_days - start_days;
    int row =(delta_days+1)/91;
    int weekday =weekdays(year,month,day);
    int days = weekday-1-row;
    while(days < 0)
        days += 5;
    if(weekday == 0 || weekday == 6)
        printf("Free.\n");
    else
        printf("%s\n",ans[days]);
    return 0; 
}  