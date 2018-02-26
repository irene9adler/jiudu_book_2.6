//�Ŷ�2.6  ������������ڲ�
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
int buf[5001][13][32];//���Ƕ���ı���ʵ�����еĴ�1 ��Ϊƽʱ����0��ʼ����

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
    }//��5000������ÿ���0��1��1�ղ��浽���յ�buf������

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
