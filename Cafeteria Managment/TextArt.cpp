#define BLOCK(x) for(int i=0;i<x;i++)cout<<char(219);
#define RT cout<<Table::RIGHT_TOP;
#define VR cout<<Table::VERTICAL;
#define LT cout<<Table::LEFT_TOP;
#define RB cout<<Table::RIGHT_BOTTOM;
#define LB cout<<Table::LEFT_BOTTOM;
#define HR(x) for(int i=0;i<x;i++)cout<<Table::HORIZONTAL;
#define TV cout<<Table::THD;
#define TH cout<<Table::THU;
#define TVLEFT cout<<Table::TVL;
#define TVRIGHT cout<<Table::TVR;
#define SPACE(x) for(int i=0;i<x;i++)cout<<" ";
#define NEWLINE cout<<endl;
class TextArt{
protected:
    void welcome(int x,int y)
    {
         gotoxy(x,y);
        BLOCK(2) RT SPACE(4) BLOCK(2) RT BLOCK(7) RT BLOCK(2) RT SPACE(6) BLOCK(6) RT SPACE(1) BLOCK(6) RT SPACE(1) BLOCK(3) RT SPACE(3) BLOCK(3) RT BLOCK(7) RT
        NEWLINE
        Sleep(50);
        gotoxy(x,y+1);
        BLOCK(2) VR SPACE(4) BLOCK(2) VR BLOCK(2) LT HR(4) RB BLOCK(2) VR SPACE(5) BLOCK(2) LT HR(4) RB BLOCK(2) LT HR(3) BLOCK(2) RT BLOCK(4) RT SPACE(1) BLOCK(4) VR BLOCK(2) LT HR(4) RB
        NEWLINE
        Sleep(50);
        gotoxy(x,y+2);
        BLOCK(2) VR SPACE(1) BLOCK(1) RT SPACE(1) BLOCK(2) VR BLOCK(5) RT SPACE(2) BLOCK(2) VR SPACE(5) BLOCK(2) VR SPACE(5) BLOCK(2) VR SPACE(3) BLOCK(2) VR BLOCK(2) LT BLOCK(4) LT BLOCK(2) VR BLOCK(5) RT
        NEWLINE
        Sleep(50);
        gotoxy(x,y+3);
        BLOCK(2) VR BLOCK(3) RT BLOCK(2) VR BLOCK(2) LT HR(2) RB SPACE(2) BLOCK(2) VR SPACE(5) BLOCK(2) VR SPACE(5) BLOCK(2) VR SPACE(3) BLOCK(2) VR BLOCK(2) VR LB BLOCK(2) LT RB BLOCK(2) VR BLOCK(2) LT HR(2) RB
        NEWLINE
        Sleep(50);
        gotoxy(x,y+4);
        LB BLOCK(3) LT BLOCK(3) LT RB BLOCK(7) RT BLOCK(7) RT LB BLOCK(6) RT LB BLOCK(6) LT RB BLOCK(2) VR SPACE(1) LB HR(1) RB SPACE(1) BLOCK(2) VR BLOCK(7) RT
        NEWLINE
        Sleep(50);
        gotoxy(x,y+5);
        SPACE(1) LB HR(2) RB LB HR(2) RB SPACE(1) LB HR(6) RB LB HR(6) RB SPACE(1) LB HR(5) RB SPACE(1) LB HR(5) RB SPACE(1) LB HR(1) RB SPACE(5) LB HR(1) RB LB HR(6) RB
    }
    void to(int x,int y)
    {
        gotoxy(x,y);
        BLOCK(8) RT SPACE(1) BLOCK(6) RT
        NEWLINE
        Sleep(50);
        gotoxy(x,y+1);
        LB HR(2) BLOCK(2) LT HR(2) RB BLOCK(2) LT HR(3) BLOCK(2) RT
        NEWLINE
        Sleep(50);
        gotoxy(x,y+2);
        SPACE(3) BLOCK(2) VR SPACE(3) BLOCK(2) VR SPACE(3) BLOCK(2) VR
        NEWLINE
        Sleep(50);
        gotoxy(x,y+3);
        SPACE(3) BLOCK(2) VR SPACE(3) BLOCK(2) VR SPACE(3)  BLOCK(2) VR
        NEWLINE
        Sleep(50);
        gotoxy(x,y+4);
        SPACE(3) BLOCK(2) VR SPACE(3) LB BLOCK(6) LT RB
        NEWLINE
        Sleep(50);
        gotoxy(x,y+5);
        SPACE(3) LB HR(1) RB SPACE(4) LB HR(5) RB
    }
    void cafe(int x,int y)
    {
        gotoxy(x,y);
        SPACE(1) BLOCK(6) RT SPACE(1) BLOCK(5) RT SPACE(1) BLOCK(7) RT BLOCK(7)  RT  SPACE(4) BLOCK(2) RT BLOCK(2) RT BLOCK(2) RT
        NEWLINE
        Sleep(50);
        gotoxy(x,y+1);
        BLOCK(2) LT HR(4) RB BLOCK(2) LT HR(2) BLOCK(2) RT BLOCK(2) LT HR(4) RB BLOCK(2) LT HR(4) RB SPACE(4) BLOCK(2) VR BLOCK(2) VR BLOCK(2) VR
        NEWLINE
        Sleep(50);
        gotoxy(x,y+2);
        BLOCK(2) VR SPACE(5) BLOCK(7) VR BLOCK(5) RT SPACE(2) BLOCK(5) RT SPACE(6) BLOCK(2) VR BLOCK(2) VR BLOCK(2) VR
        NEWLINE
        Sleep(50);
        gotoxy(x,y+3);
        BLOCK(2) VR SPACE(5) BLOCK(2) LT HR(2) BLOCK(2) VR BLOCK(2) LT HR(2) RB SPACE(2) BLOCK(2) LT HR(2) RB SPACE(6) LB HR(1) RB LB HR(1) RB LB HR(1) RB
        NEWLINE
        Sleep(50);
        gotoxy(x,y+4);
        LB BLOCK(6) RT BLOCK(2) VR SPACE(2) BLOCK(2) VR BLOCK(2) VR SPACE(5) BLOCK(7) RT SPACE(4) BLOCK(2) RT BLOCK(2) RT BLOCK(2) RT
        NEWLINE
        Sleep(50);
        gotoxy(x,y+5);
        SPACE(1) LB HR(5) RB LB HR(1) RB SPACE(2) LB HR(1) RB LB HR(1) RB SPACE(5) LB HR(6) RB SPACE(4) LB HR(1) RB LB HR(1) RB LB HR(1) RB

    }
public:
    void letter_E(int,int);
    void space(int,int,int);
    void curser(int,int,int);
    void curser(int,int);
    void letter_W(int,int);
    void letter_L(int,int);
    void letter_C(int,int);
    void letter_O(int,int);
    void letter_M(int,int);
    void letter_T(int,int);
    void letter_A(int,int);
    void letter_F(int,int);
    void TypeEffect(int,int);
    void user_login_text(int,int);
};
void TextArt::user_login_text(int x,int y)
{
    gotoxy(x,y);
    TV SPACE(1) TV SPACE(1) LT HR(1) RT SPACE(1) LT HR(1) RT SPACE(1) TV HR(1) RT SPACE(4) TV SPACE(3) LT HR(1) RT SPACE(1) LT HR(1) RT SPACE(1) TV SPACE(1) LT RT LT
    NEWLINE
    gotoxy(x,y+1);
    VR SPACE(1) VR SPACE(1) LB HR(1) RT SPACE(1) VR TVLEFT SPACE(2)  TVRIGHT TV RB SPACE(4) VR SPACE(3) VR SPACE(1) VR SPACE(1) VR SPACE(1) TV  SPACE(1) VR SPACE(1) VR VR VR
    NEWLINE
    gotoxy(x,y+2);
    LB HR(1) RB SPACE(1) LB HR(1) RB SPACE(1) LB HR(1) RB SPACE(1) TH LB HR(1) SPACE(4) TH HR(1) RB SPACE(1) LB HR(1) RB SPACE(1)  LB HR(1) RB  SPACE(1)  TH SPACE(1) RB LB RB

}
void TextArt::letter_E(int x,int y)
    {
        gotoxy(x,y);
        BLOCK(7) RT
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(2) LT HR(4) RB
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(5) RT SPACE(2)
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) LT HR(2) RB SPACE(2)
        NEWLINE
        gotoxy(x,y+4);
        BLOCK(7) RT
        NEWLINE
        gotoxy(x,y+5);
        LB HR(6) RB
    }
void TextArt::space(int x,int y,int space)
    {
        gotoxy(x,y);
        SPACE(space)
        gotoxy(x,y+1);
        SPACE(space)
        gotoxy(x,y+2);
        SPACE(space)
        gotoxy(x,y+3);
        SPACE(space)
        gotoxy(x,y+4);
        SPACE(space)
        gotoxy(x,y+5);
        SPACE(space);
    }
void TextArt::curser(int x,int y,int color)
    {
        Utility::saveDefaultColor();
        Utility::setColor(color);
        gotoxy(x,y);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+4);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+5);
        BLOCK(1)
        Utility::resetColor();
    }
void TextArt::curser(int x,int y)
    {
        gotoxy(x,y);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+4);
        BLOCK(1)
        NEWLINE
        gotoxy(x,y+5);
        BLOCK(1)
    }
    void TextArt::letter_W(int x,int y)
    {
        gotoxy(x,y);
        BLOCK(2) RT SPACE(4) BLOCK(2) RT
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(2) VR SPACE(4) BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(2) VR SPACE(1) BLOCK(1) RT SPACE(1) BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) VR BLOCK(3) RT BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+4);
        LB BLOCK(3) LT BLOCK(3) LT RB
        NEWLINE
        gotoxy(x,y+5);
        SPACE(1) LB HR(2) RB LB HR(2) RB
    }
void TextArt::letter_L(int x,int y)
{
        gotoxy(x,y);
        BLOCK(2) RT SPACE(5)
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(2) VR SPACE(5)
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(2) VR SPACE(5)
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) VR SPACE(5)
        NEWLINE
        gotoxy(x,y+4);
        BLOCK(7) RT
        NEWLINE
        gotoxy(x,y+5);
        LB HR(6) RB
}
void TextArt::letter_C(int x,int y)
{
        gotoxy(x,y);
        SPACE(1) BLOCK(6) RT
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(2) LT HR(4) RB
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(2) VR SPACE(5)
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) VR SPACE(5)
        NEWLINE
        gotoxy(x,y+4);
        LB BLOCK(6) RT
        NEWLINE
        gotoxy(x,y+5);
        SPACE(1) LB HR(5) RB
}
void TextArt::letter_O(int x,int y)
{
        gotoxy(x,y);
        SPACE(1) BLOCK(6) RT
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(2) LT HR(3) BLOCK(2) RT
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(2) VR SPACE(3) BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) VR SPACE(3) BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+4);
        LB BLOCK(6) LT RB
        NEWLINE
        gotoxy(x,y+5);
        SPACE(1) LB HR(5) RB
}
void TextArt::letter_M(int x,int y)
{
        gotoxy(x,y);
        BLOCK(3) RT SPACE(3) BLOCK(3) RT
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(4) RT SPACE(1) BLOCK(4) VR
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(2) LT BLOCK(4) LT BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) VR LB BLOCK(2) LT RB BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+4);
        BLOCK(2) VR SPACE(1) LB HR(1) RB SPACE(1) BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+5);
        LB HR(1) RB SPACE(5) LB HR(1) RB
}
void TextArt::letter_T(int x,int y)
{
        gotoxy(x,y);
        BLOCK(8) RT
        NEWLINE
        gotoxy(x,y+1);
        LB HR(2) BLOCK(2) LT HR(2) RB
        NEWLINE
        gotoxy(x,y+2);
        SPACE(3) BLOCK(2) VR SPACE(3)
        NEWLINE
        gotoxy(x,y+3);
        SPACE(3) BLOCK(2) VR SPACE(3)
        NEWLINE
        gotoxy(x,y+4);
        SPACE(3) BLOCK(2) VR SPACE(3)
        NEWLINE
        gotoxy(x,y+5);
        SPACE(3) LB HR(1) RB  SPACE(3)
}
void TextArt::letter_A(int x,int y)
{
        gotoxy(x,y);
        SPACE(1) BLOCK(5) RT SPACE(1)
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(2) LT HR(2) BLOCK(2) RT
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(7) VR
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) LT HR(2) BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+4);
        BLOCK(2) VR SPACE(2) BLOCK(2) VR
        NEWLINE
        gotoxy(x,y+5);
        LB HR(1) RB SPACE(2) LB HR(1) RB
}
void TextArt::letter_F(int x,int y)
{
        gotoxy(x,y);
        BLOCK(7) RT
        NEWLINE
        gotoxy(x,y+1);
        BLOCK(2) LT HR(4) RB
        NEWLINE
        gotoxy(x,y+2);
        BLOCK(5) RT SPACE(2)
        NEWLINE
        gotoxy(x,y+3);
        BLOCK(2) LT HR(2) RB SPACE(2)
        NEWLINE
        gotoxy(x,y+4);
        BLOCK(2) VR SPACE(5)
        NEWLINE
        gotoxy(x,y+5);
        LB HR(1) RB
}
void TextArt::TypeEffect(int x,int y)
{
        system("cls");
        system(" color 3f");
        TextArt T;
        T.curser(25,10);
        Sleep(500);
        T.letter_W(25,10);
        T.curser(36,10);
        Sleep(130);
        T.letter_E(36,10);
        T.curser(45,10);
        Sleep(130);
        T.letter_L(45,10);
        T.curser(53,10);
        Sleep(130);
        T.letter_C(53,10);
        T.curser(62,10);
        Sleep(130);
        T.letter_O(62,10);
        T.curser(72,10);
        Sleep(130);
        T.letter_M(72,10);
        T.curser(84,10);
        Sleep(130);
        T.letter_E(84,10);
        T.curser(93,10);
        Sleep(1000);
        T.space(84,10,8);
        T.curser(93,10,Utility::CYAN);
        T.curser(84,10);
        Sleep(30);
        T.space(72,10,11);
        T.curser(84,10,Utility::CYAN);
        T.curser(72,10);
        Sleep(30);
        T.space(62,10,9);
        T.curser(72,10,Utility::CYAN);
        T.curser(62,10);
        Sleep(30);
        T.space(53,10,8);
        T.curser(62,10,Utility::CYAN);
        T.curser(53,10);
        Sleep(30);
        T.space(45,10,8);
        T.curser(53,10,Utility::CYAN);
        T.curser(45,10);
        Sleep(30);
        T.space(36,10,8);
        T.curser(45,10,Utility::CYAN);
        T.curser(36,10);
        Sleep(30);
        T.space(25,10,10);
        T.curser(36,10,Utility::CYAN);
        T.curser(25,10);
        system("cls");
        T.curser(25,10);
        Sleep(200);
        T.letter_T(25,10);
        T.curser(35,10);
        Sleep(130);
        T.letter_O(35,10);
        T.curser(45,10);
        Sleep(1000);
        T.space(35,10,9);
        T.curser(45,10,Utility::CYAN);
        T.curser(35,10);
        Sleep(30);
        T.space(25,10,9);
        T.curser(35,10,Utility::CYAN);
        T.curser(25,10);
        system("cls");
        T.curser(25,10);
        Sleep(200);
        T.letter_C(25,10);
        T.curser(34,10);
        Sleep(130);
        T.letter_A(34,10);
        T.curser(43,10);
        Sleep(130);
        T.letter_F(43,10);
        T.curser(52,10);
        Sleep(130);
        T.letter_E(52,10);
        T.curser(61,10);
        Sleep(1000);
        T.space(52,10,9);
        T.curser(61,10,Utility::CYAN);
        T.curser(52,10);
        Sleep(30);
        T.space(43,10,9);
        T.curser(52,10,Utility::CYAN);
        T.curser(43,10);
        Sleep(30);
        T.space(34,10,9);
        T.curser(43,10,Utility::CYAN);
        T.curser(34,10);
        Sleep(30);
        T.space(25,10,9);
        T.curser(34,10,Utility::CYAN);
        T.curser(25,10);
        Utility::resetColor();
}
