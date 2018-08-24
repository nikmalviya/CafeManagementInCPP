#include<iomanip>
class Time{
    char day[10],suffix[10];
    int date,month,year,hour,minute;
public:
    Time()
    {
        SYSTEMTIME t;
        GetLocalTime(&t);
        int d=t.wDayOfWeek;
        switch(d)
        {
        case 0:
            strcpy(day,"SUN");
            break;
        case 1:
            strcpy(day,"MON");
            break;
        case 2:
            strcpy(day,"TUE");
            break;
        case 3:
            strcpy(day,"WED");
            break;
        case 4:
            strcpy(day,"THUR");
            break;
        case 5:
            strcpy(day,"FRI");
            break;
        case 6:
            strcpy(day,"SAT");
            break;
        default:
            cout<<endl;
        }
        date=t.wDay;
        month=t.wMonth;
        year=t.wYear;
        hour=t.wHour;
        minute=t.wMinute;
        if(hour>11)
            {
                hour-=12;
                strcpy(suffix,"PM");
            }
        else
            strcpy(suffix,"AM");
        if(hour==0)
            hour=12;
    }
    char *getDay();
    int getDate();
    int getMonth();
    int getYear();
    int getHour();
    int getMinute();
    char *getSuffix();
    void displayTime();
};
void Time::displayTime()
{
    cout<<setfill('0');
    cout<<' '<<day<<' '<<setw(2)<<date<<'/'<<setw(2)<<month<<'/'<<setw(2)<<year<<' '<<setw(2)<<hour<<':'<<setw(2)<<minute<<' '<<suffix<<' '<<endl;
}
char* Time::getDay()
{
    return day;
}
int Time::getDate()
{
    return date;
}
int Time::getMonth()
{
    return month;
}
int Time::getYear()
{
    return year;
}
int Time::getHour()
{
    return hour;
}
int Time::getMinute()
{
    return minute;
}
char* Time::getSuffix()
{
    return suffix;
}
