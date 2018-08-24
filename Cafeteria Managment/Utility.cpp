#include "Utility.h"
#include<cstring>
#include<string>
using namespace std;
namespace Table
{
    const char THD = char(203);
    const char TVR = char(204);
    const char TVL = char(185);
    const char THU = char(202);
    const char VERTICAL   = char(186);
    const char HORIZONTAL = char(205);
    const char LEFT_TOP   = char(201);
    const char LEFT_BOTTOM= char(200);
    const char RIGHT_TOP  = char(187);
    const char RIGHT_BOTTOM = char(188);

}
class TextEffects {
public:
    void floatingText(string str,int x,int y,int length,int time)
    {
        for(int i=x;i<=length+x;i++)
        {
            gotoxy(i,y);
            cout<<" ";
            cout<<str;
            Sleep(time);
        }
    }
    void typingText(string str,int x,int y,int sleep)
    {
        gotoxy(x,y);
        for(int i=0;i<str.length();i++)
        {
            cout<<str[i];
            Sleep(sleep);
        }
    }
};
class Shape
{
    public:
    void drawSolidBox(int x1,int y1,int x2,int y2,int color_code,int delay=0)
    {
        Utility::saveDefaultColor();
        Utility::setBackgroundColor(color_code);
        int length = x2-x1;
        int height = y2-y1;
        gotoxy(x1,y1);
        for(int i=0;i<height;i++)
        {
            gotoxy(x1,++y1);
            for(int j=0;j<length;j++)
            {
                cout<<" ";
            }
            Sleep(delay);
            cout<<endl;
        }
        Utility::resetColor();
    }
    void drawBorderedBox(int x1,int y1,int x2,int y2,int foreground_color,int background_color,int delay=0)
    {
        Utility::saveDefaultColor();
        Utility::setBackgroundColor(background_color);
        Utility::setColor(foreground_color);
        int length = x2-x1;
        int height = y2-y1;
        gotoxy(x1,y1);
        for(int i=0;i<height;i++)
        {
            gotoxy(x1,++y1);
            for(int j=0;j<length;j++)
            {
                if(i==0&&j==0)
                    cout<<Table::LEFT_TOP;
                else if(i==height-1&&j==0)
                    cout<<Table::LEFT_BOTTOM;
                else if(i==0&&j==length-1)
                    cout<<Table::RIGHT_TOP;
                else if(i==height-1&&j==length-1)
                    cout<<Table::RIGHT_BOTTOM;
                else if(i==0||i==height-1)
                    cout<<Table::HORIZONTAL;
                else if(j==0||j==length-1)
                    cout<<Table::VERTICAL;
                else
                    cout<<" ";
            }
            Sleep(delay);
            cout<<endl;
        }
        Utility::resetColor();
    }
    void drawBorderedBox(int x1,int y1,int x2,int y2)
    {
        int length = x2-x1;
        int height = y2-y1;
        gotoxy(x1,y1);
        for(int i=0;i<height;i++)
        {
            gotoxy(x1,++y1);
            for(int j=0;j<length;j++)
            {
                if(i==0&&j==0)
                    cout<<Table::LEFT_TOP;
                else if(i==height-1&&j==0)
                    cout<<Table::LEFT_BOTTOM;
                else if(i==0&&j==length-1)
                    cout<<Table::RIGHT_TOP;
                else if(i==height-1&&j==length-1)
                    cout<<Table::RIGHT_BOTTOM;
                else if(i==0||i==height-1)
                    cout<<Table::HORIZONTAL;
                else if(j==0||j==length-1)
                    cout<<Table::VERTICAL;
                else
                    cout<<" ";
            }
            cout<<endl;
        }
    }
};
class Widget:public Shape{
public:
    void dialogBox(const char title[],int x1,int y1,int x2,int y2,int foreground_color,int background_color,int delay=0)
    {
        drawSolidBox(x1,y1,x2,y2,background_color,delay);
        drawBorderedBox(x1+2,y1+1,x2-2,y2-1,foreground_color,background_color,delay);
        gotoxy(x1+6,y1+2);
        Utility::setBackgroundColor(background_color);
        Utility::setColor(foreground_color);
        cout<<title;
        Utility::resetColor();
    }
    void alertBox(const char alertmsg[],int x1,int y1,int x2,int y2,int foreground_color,int background_color)
    {
        int len=strlen(alertmsg);
        len/=2;
        int x=x2-x1;
        x/=2;
        int y=y2-y1;
        y/=2;
        drawSolidBox(x1,y1,x2,y2,background_color);
        drawBorderedBox(x1+2,y1+1,x2-2,y2-1,foreground_color,background_color);
        gotoxy(x+x1-len,y+y1);
        label(alertmsg,foreground_color,background_color);
        gotoxy(x1+x-3,y2-3);
        label("  OK  ",Utility::BLACK,Utility::GREY);
        getch();
        Utility::resetColor();
    }
    void textBox(int length=15)
    {
        Utility::saveDefaultColor();
        Utility::setBackgroundColor(Utility::WHITE);
        for(int i=0;i<length;i++)
        {
            cout<<" ";
        }
        Utility::resetColor();
    }
    void textBox(int length,int background_color)
    {
        Utility::saveDefaultColor();
        Utility::setBackgroundColor(background_color);
        for(int i=0;i<length;i++)
        {
            cout<<" ";
        }
        Utility::resetColor();
    }
    string getEncryptedText()
    {
        char ch;
        string str;
        do
        {
            ch=getch();
            if(ch!=13 and ch!=8)
            {
                if(str.length()<20)
                {
                    cout<<"*";
                    str=str+ch;
                }

            } else if(ch==8)
            {
                cout<<"\b \b";
                str = str.substr(0,str.length()-1);
            }

        }while(ch!=13);
        return str;
    }
    void label(const char label[],int foreground_color,int background_color)
    {
        Utility::saveDefaultColor();
        Utility::setBackgroundColor(background_color);
        Utility::setColor(foreground_color);
        cout<<label;
    }
};
