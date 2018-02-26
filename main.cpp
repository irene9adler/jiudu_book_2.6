//九度2.6  计算两天的日期差
#include <stdio.h>

int Month[13][2] = {0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};

int runnian (int year)
{
    if(year%400 == 0) return 1;
    if((year%100!=0)&&(year%4==0)) return 1;
    return 0;
   /* else
    {
        if (year%100!=0)
        {
            if(year%4==0) return 1;
        }
        return 0;
    }*/
}

struct day
{
    int year;
    int month;
    int day;

    void nextday()
    {
        day++;
        int l = runnian(year);
        if(day>Month[month][l])
        {
             day = 1;
             month++;
        if(month>12)
         {
            month = 1;
            year++;
         }

        }
    }
};
int buf[5001][13][32];//都是定义的比他实际上有的大1 因为平时不从0开始计数

int main()
{
    day today;
    today.day = 1;
    today.month = 1;
    today.year = 0;
    int cnt = 0;
    while(today.year<=5000)
    {
        buf[today.year][today.month][today.day] = cnt;
        today.nextday();
        cnt ++;
    }//把5000年以内每天和0年1月1日差几天存到该日的buf数组里

    int d1,m1,y1;
    int d2,m2,y2;
    int result;
    while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
    {
        scanf("%4d%2d%2d",&y2,&m2,&d2);
            result = buf[y1][m1][d1] - buf[y2][m2][d2];
            if(result>0) printf("%d\n",result);
            else
            {
                result = -result;
                printf("%d\n",result);
            }
    }
    return 0;
}
