#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cctype>
#include "Utility.cpp"
#include"TextArt.cpp"
#include"Time.cpp"
#include"UserData.cpp"
#include"Menu.cpp"
#include"OrderMenu.cpp"
#include"Product.cpp"
#include"Admin.cpp"
using namespace std;
inline void borderedScreen()
{
        Shape box;
        box.drawBorderedBox(3,1,119,28,Utility::WHITE,Utility::CYAN);
}
class StartPage:protected TextArt{
public:
    void start_page();
};
class Login{
protected:
    UserData user;
    void loginPage();
    void loginProgram();
public:
    void user_login();
};
class MainMenu{
public:
    void main_menu_layout();
    void main_menu_program();
};
class CreateAccount{
    UserData user;
public:
    void createAccountPage1();
    void createAccountPage2();
    void createAccountProgram1();
    void createAccountProgram2();
    void creatingAccount();
};
void CreateAccount::creatingAccount()
{
    borderedScreen();
    Widget wdg;
    system("color 3f");
    wdg.drawSolidBox(40,8,75,17,15);
    wdg.drawBorderedBox(41,8,74,17,0,15);
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    gotoxy(47,14);
    cout<<"Creating Your Account";
    gotoxy(52,12);
    Utility::hidecursor();
    cout<<"Loading";
    char dots[]="...";
    for(char a:dots)
    {
        Sleep(1000);
        cout<<a;
    }
    fstream file("UserData.txt",ios::in|ios::out|ios::app);
    file<<user;
    file.close();
    wdg.drawSolidBox(40,8,75,17,15);
    wdg.drawBorderedBox(41,8,74,17,0,15);
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    gotoxy(51,12);
    cout<<"Your Account";
    gotoxy(47,14);
    cout<<"Created Successfully..";
    Sleep(500);
    wdg.drawSolidBox(35,7,80,18,15);
    wdg.drawBorderedBox(36,7,79,18,0,15);
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    TextEffects t;
    t.typingText(string("LOGIN CREDENTIALS"),49,10,50);
    gotoxy(40,12);
    cout<<"E-Mail   ::: "<<user.getEmail()<<endl;
    gotoxy(40,14);
    cout<<"Password ::: "<<user.getPassword()<<endl;
    gotoxy(50,16);
    Utility::hidecursor();
    wdg.label(" PRESS ANY KEY ",Utility::WHITE,Utility::CYAN);
    getch();
    MainMenu m;
    m.main_menu_layout();
    m.main_menu_program();
}
void CreateAccount::createAccountProgram1()
{
    UserData user_temp;
    Widget wdg;
    Utility::setBackgroundColor(Utility::WHITE);
    Utility::setColor(Utility::BLACK);
    gotoxy(55,11);
    string temp;
    cin>>temp;
    user.setFirstName(temp);
    gotoxy(55,13);
    cin>>temp;
    user.setLastName(temp);
    gotoxy(55,15);
    cin>>temp;
    ifstream fin("UserData.txt");
    while(fin>>user_temp)
    {
        if(user_temp.getEmail()==temp)
            break;
    }
    if(temp==user_temp.getEmail())
    {
        wdg.alertBox("Account Already Exist",40,8,75,17,0,15);
        createAccountPage1();
        createAccountProgram1();
    }
    else
    {
        user.setEmail(temp);
    }
    gotoxy(55,17);
    cin>>temp;
    user.setContactNumber(temp);
    gotoxy(55,19);
    cin>>temp;
    user.setDateOfBirth(temp);
    fin.close();
    int key_counter=0,input_validate=0;
    Utility::hidecursor();
    while(true)
    {
            switch(key_counter)
            {
            case 0:
                gotoxy(59,22);
                wdg.label("  NEXT  ",Utility::BLACK,Utility::CYAN);
                gotoxy(48,22);
                wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    MainMenu m;
                    m.main_menu_layout();
                    m.main_menu_program();
                }
                break;
            case 1:
                gotoxy(48,22);
                wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
                gotoxy(59,22);
                wdg.label("  NEXT  ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    createAccountPage2();
                    createAccountProgram2();
                    break;
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
}
void CreateAccount::createAccountProgram2()
{
    Utility::showcursor();
    Utility::setBackgroundColor(Utility::WHITE);
    Utility::setColor(Utility::BLACK);
    gotoxy(56,11);
    Widget wdg;
    long int balance;
    string temp;
    cin>>temp;
    user.setCity(temp);
    gotoxy(56,13);
    cin>>balance;
    user.setBalance(balance);
    gotoxy(56,15);
    temp = wdg.getEncryptedText();
    gotoxy(56,17);
    string temp1 = wdg.getEncryptedText();
    if(temp==temp1)
    {
        if(temp.length()<8)
        {
            wdg.alertBox("Minimum 8 Chars Required",40,8,75,17,0,15);
            createAccountPage2();
            createAccountProgram2();
        }
        else
            user.setPassword(temp);
    }
    else
    {
        wdg.alertBox("Password Not Matched",40,8,75,17,0,15);
        createAccountPage2();
        createAccountProgram2();
    }
    int key_counter=0,input_validate=0;
    Utility::hidecursor();
    while(true)
    {
            switch(key_counter)
            {
            case 0:
                gotoxy(59,20);
                wdg.label("  NEXT  ",Utility::BLACK,Utility::CYAN);
                gotoxy(48,20);
                wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    MainMenu m;
                    m.main_menu_layout();
                    m.main_menu_program();
                }
                break;
            case 1:
                gotoxy(48,20);
                wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
                gotoxy(59,20);
                wdg.label("  NEXT  ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    creatingAccount();

                    break;
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
}
void CreateAccount::createAccountPage1()
{
        //system("color 3f");
        borderedScreen();
        Shape s;
        Widget w;TextEffects text;
        //system("color 3f");
        w.dialogBox(" -: CREATE ACCOUNT :- ",25,5,90,26,Utility::BLACK,Utility::GREY);
        Utility::setColor(Utility::RED);
        text.typingText(string(" -: ENTER YOUR DETAILS :- "),45,9,30);
        gotoxy(37,11);
        w.label("FIRST NAME    :",Utility::BLUE,Utility::GREY);
        gotoxy(54,11);
        w.textBox(25);
        gotoxy(55,11);
        w.label("First Name ....",11,Utility::WHITE);
        gotoxy(37,13);
        w.label("LAST NAME     :",Utility::BLUE,Utility::GREY);
        gotoxy(54,13);
        w.textBox(25);
        gotoxy(55,13);
        w.label("Last Name ....",11,Utility::WHITE);
        gotoxy(37,15);
        w.label("E-Mail        :",Utility::BLUE,Utility::GREY);
        gotoxy(54,15);
        w.textBox(25);
        gotoxy(55,15);
        w.label("abc@xyz.com ",11,Utility::WHITE);
        gotoxy(37,17);
        w.label("CONTACT NO.   :",Utility::BLUE,Utility::GREY);
        gotoxy(54,17);
        w.textBox(25);
        gotoxy(55,17);
        w.label("Contact No .... ",11,Utility::WHITE);
        gotoxy(37,19);
        w.label("DATE OF BIRTH.:",Utility::BLUE,Utility::GREY);
        gotoxy(54,19);
        w.textBox(25);
        gotoxy(55,19);
        w.label("DD/MM/YYYY",11,Utility::WHITE);
        gotoxy(48,22);
        w.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
        gotoxy(59,22);
        w.label("  NEXT  ",Utility::BLACK,Utility::CYAN);
}
void CreateAccount::createAccountPage2()
{
        //system("color 3f");
        //borderedScreen();
        Shape s;
        Widget w;TextEffects text;
        //system("color 3f");
        w.dialogBox(" -: CREATE ACCOUNT :- ",25,5,90,26,Utility::BLACK,Utility::GREY);
        Utility::setColor(Utility::RED);
        text.typingText(string(" -: ENTER YOUR DETAILS :- "),45,9,20);
        gotoxy(37,11);
        w.label("CITY            :",Utility::BLUE,Utility::GREY);
        gotoxy(55,11);
        w.textBox(25);
        gotoxy(56,11);
        w.label("City ....",11,Utility::WHITE);
        gotoxy(37,13);
        w.label("INITIAL BALANCE :",Utility::BLUE,Utility::GREY);
        gotoxy(55,13);
        w.textBox(25);
        gotoxy(56,13);
        w.label("RS Amount ....",11,Utility::WHITE);
        gotoxy(37,15);
        w.label("PASSWORD        :",Utility::BLUE,Utility::GREY);
        gotoxy(55,15);
        w.textBox(25);
        gotoxy(56,15);
        w.label("Min 8 Characters..",11,Utility::WHITE);
        gotoxy(37,17);
        w.label("CONFIRM PASSWORD:",Utility::BLUE,Utility::GREY);
        gotoxy(55,17);
        w.textBox(25);
        gotoxy(56,17);
        w.label("Your Password..",11,Utility::WHITE);
        gotoxy(48,20);
        w.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
        gotoxy(59,20);
        w.label("  NEXT  ",Utility::BLACK,Utility::CYAN);
}
void StartPage::start_page()
{
    //system("COLOR F4");
    borderedScreen();
    welcome(25,5);
    to(45,12);
    cafe(35,19);
    string s = "COLOR F";
    for(int i=49;i<54;i++)
    {
        s+=i;
        system(s.c_str());
        Sleep(100);
        s.erase(s.end()-1);
    }
    system("color 3f");
}

void MainMenu::main_menu_layout()
{
    //system("color 3f");
    Utility::hidecursor();
    borderedScreen();
    Widget wdg;
    wdg.dialogBox(" MAIN MENU ",26,6,95,22,Utility::BLACK,Utility::GREY,0);
    TextEffects t;
    Utility::saveDefaultColor();

    t.typingText(string(" -: Welcome To Cafe !!! :- "),45,12,20);
    gotoxy(40,14);
    wdg.label(" ==> ",Utility::WHITE,Utility::CYAN);
    Utility::setBackgroundColor(Utility::GREY);
    Utility::setColor(Utility::BLACK);
    t.typingText(string("Login To Your Account "),50,14,15);
    gotoxy(40,16);
    wdg.label(" ==> ",Utility::WHITE,Utility::CYAN);
    Utility::setBackgroundColor(Utility::GREY);
    Utility::setColor(Utility::BLACK);
    t.typingText(string("Create New Account "),50,16,15);
    gotoxy(40,18);
    wdg.label(" ==> ",Utility::WHITE,Utility::CYAN);
    Utility::setBackgroundColor(Utility::GREY);
    Utility::setColor(Utility::BLACK);
    t.typingText(string("Exit "),50,18,15);
    Time time;
    gotoxy(65,9);
    time.displayTime();
    Utility::resetColor();
}
void Admin::admin_login()
{
        borderedScreen();
        Widget wdg;
        Utility::setColor(4);
        Utility::setBackgroundColor(7);
        wdg.dialogBox(" LOGIN ",35,8,80,19,Utility::BLACK,Utility::GREY);
        gotoxy(40,12);
        wdg.label("USERNAME ::: ",Utility::BLACK,Utility::GREY);
        gotoxy(55,12);
        wdg.textBox(17);
        gotoxy(40,14);
        wdg.label("PASSWORD ::: ",Utility::BLACK,Utility::GREY);
        gotoxy(55,14);
        wdg.textBox(17);
        gotoxy(47,16);
        wdg.label(" LOGIN ",Utility::BLACK,Utility::CYAN);
        gotoxy(56,16);
        wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
        string username;
        string password;
        int key_counter=0,input_validate=0;
        Utility::saveDefaultColor();
        Utility::setBackgroundColor(Utility::WHITE);
        Utility::setColor(Utility::BLACK);
        gotoxy(55,12);
        Utility::showcursor();
        cin>>username;
        gotoxy(55,14);
        password=wdg.getEncryptedText();
        Utility::hidecursor();
        while(true)
        {
            switch(key_counter)
            {
            case 0:
                gotoxy(56,16);
                wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
                gotoxy(47,16);
                wdg.label(" LOGIN ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    if(username=="admin" and password == "admin")
                    {
                        Admin admin;
                        admin.admin_menu();
                        admin.admin_menu_program();
                    }
                    else
                        {
                            wdg.alertBox(" INVALID LOGIN CREDENTIALS",40,9,75,18,Utility::BLACK,Utility::WHITE);
                            input_validate=0;
                            Utility::showcursor();
                            admin_login();
                        }
                }
                break;
            case 1:
                gotoxy(47,16);
                wdg.label(" LOGIN ",Utility::BLACK,Utility::CYAN);
                gotoxy(56,16);
                wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    MainMenu m;
                    m.main_menu_layout();
                    m.main_menu_program();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
        Utility::saveDefaultColor();
}
void Login::loginProgram()
{
        string username;
        string password;
        int key_counter=0,input_validate=0;
        Widget wdg;
        Utility::saveDefaultColor();
        Utility::setBackgroundColor(Utility::WHITE);
        Utility::setColor(Utility::BLACK);
        gotoxy(55,14);
        Utility::showcursor();
        cin>>username;
        gotoxy(55,16);
        password=wdg.getEncryptedText();
        ifstream fin;
        fin.open("UserData.txt");
        Utility::hidecursor();
        while(true)
        {
            switch(key_counter)
            {
            case 0:
                gotoxy(56,18);
                wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
                gotoxy(47,18);
                wdg.label(" LOGIN ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    while(fin>>user)
                    {
                        if(user.getEmail()==username)
                            break;
                    }
                    if(username==user.getEmail() and password == user.getPassword())
                    {
                        fin.close();
                        ofstream file1("ActiveUser.txt");
                        file1<<user;
                        file1.close();
                        Menu menu;
                        menu.menu_layout();
                        menu.menu_program();
                    }
                    else
                        {
                            wdg.alertBox(" INVALID LOGIN CREDENTIALS",40,10,75,19,Utility::BLACK,Utility::WHITE);
                            input_validate=0;
                            Utility::showcursor();
                            fin.close();
                            loginPage();
                            loginProgram();
                        }
                }
                break;
            case 1:
                gotoxy(47,18);
                wdg.label(" LOGIN ",Utility::BLACK,Utility::CYAN);
                gotoxy(56,18);
                wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    MainMenu m;
                    m.main_menu_layout();
                    m.main_menu_program();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
        Utility::saveDefaultColor();
}
void Login::loginPage()
{

        Widget wdg;
        TextArt textart;
        wdg.drawBorderedBox(35,3,80,8,Utility::BLUE,Utility::GREY);
        Utility::setColor(4);
        Utility::setBackgroundColor(7);
        textart.user_login_text(39,5);
        wdg.dialogBox(" LOGIN ",35,10,80,21,Utility::BLACK,Utility::GREY);
        gotoxy(40,14);
        wdg.label("USERNAME ::: ",Utility::BLACK,Utility::GREY);
        gotoxy(55,14);
        wdg.textBox(17);
        gotoxy(40,16);
        wdg.label("PASSWORD ::: ",Utility::BLACK,Utility::GREY);
        gotoxy(55,16);
        wdg.textBox(17);
        gotoxy(47,18);
        wdg.label(" LOGIN ",Utility::BLACK,Utility::CYAN);
        gotoxy(56,18);
        wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
}
void Login::user_login()
{
    //system("color 3f");
    borderedScreen();
    loginPage();
    loginProgram();
}
void MainMenu::main_menu_program()
{
    int key_counter=0,input_validate=0;
    Utility::hidecursor();
    Widget wdg;
    Login s;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(40,18);
                wdg.label(" ==> ",Utility::WHITE,Utility::CYAN);
                gotoxy(40,14);
                wdg.label(" ==> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    TextArt t;
                    t.TypeEffect(2,2);
                    s.user_login();
                }
                break;
            case 1:
                gotoxy(40,14);
                wdg.label(" ==> ",Utility::WHITE,Utility::CYAN);
                gotoxy(40,16);
                wdg.label(" ==> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    CreateAccount c;
                    c.createAccountPage1();
                    Utility::showcursor();
                    c.createAccountProgram1();
                }
                break;
            case 2:
                gotoxy(40,16);
                wdg.label(" ==> ",Utility::WHITE,Utility::CYAN);
                gotoxy(40,18);
                wdg.label(" ==> ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    exit(0);
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_HOME)
                {
                    if(key==Utility::KEY_HOME)
                    {
                        Admin admin;
                        admin.admin_login();
                        admin.admin_menu();
                        admin.admin_menu_program();
                    }
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                    }
                }
                if(key_counter>2)
                    key_counter=0;
            }
        }
}
void Menu::menu_layout()
{
    borderedScreen();
    Widget wdg;
    Shape shape;
    shape.drawSolidBox(7,2,115,5,7);
    shape.drawBorderedBox(9,2,113,5,0,7);
    wdg.dialogBox(" -: ORDER FOOD :- ",7,6,60,13,Utility::BLACK,Utility::GREY);
    wdg.dialogBox(" -: OFFERS :- ",7,14,60,27,Utility::BLACK,Utility::GREY);
    wdg.dialogBox(" -: USER INFO :- ",62,6,115,16,Utility::BLACK,Utility::GREY);
    wdg.dialogBox(" -: MY ACCOUNT :- ",62,17,115,27,Utility::BLACK,Utility::GREY);
    gotoxy(12,10);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(30,10);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    gotoxy(17,10);
    Utility::setColor(0);;
    Utility::setBackgroundColor(7);
    cout<<" ORDER MENU ";
    gotoxy(35,10);
    cout<<" VIEW RECENT ORDERS ";
    gotoxy(12,18);
    wdg.label(" FAST FOOD ",15,3);
    gotoxy(23,18);
    wdg.label(" ICE CREAM ",15,3);
    gotoxy(34,18);
    wdg.label(" COLD DRINKS ",15,3);
    gotoxy(47,18);
    wdg.label(" SNACKS ",15,3);
    gotoxy(15,20);
    Utility::setColor(4);;
    Utility::setBackgroundColor(7);
    cout<<"PRODUCTS";
    gotoxy(29,20);
    cout<<"DISCOUNT";
    gotoxy(43,20);
    cout<<"AVAILABLE";
    gotoxy(68,10);
    wdg.label(" WALLET BALANCE -> ",Utility::BLACK,Utility::GREY);
    gotoxy(88,10);
    wdg.textBox();
    gotoxy(89,10);
    wdg.label("RS",Utility::BLACK,Utility::WHITE);
    gotoxy(69,12);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    wdg.label("  VIEW TRANSACTIONS ",Utility::BLACK,Utility::GREY);
    gotoxy(69,14);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    wdg.label("  ADD BALANCE ",Utility::BLACK,Utility::GREY);
    gotoxy(88,14);
    wdg.textBox();
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(89,14);
    wdg.label("RS",Utility::BLACK,Utility::WHITE);
    gotoxy(68,21);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    wdg.label("  VIEW DETAILS",Utility::BLACK,Utility::GREY);
    gotoxy(92,21);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    wdg.label("  EDIT DETAILS",Utility::BLACK,Utility::GREY);
    gotoxy(68,24);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    wdg.label("  CHANGE PASSWORD",Utility::BLACK,Utility::GREY);
    gotoxy(92,24);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
    wdg.label("  LOGOUT",Utility::BLACK,Utility::GREY);
    gotoxy(12,4);
    Utility::setColor(1);
    Utility::setBackgroundColor(7);
    cout<<" WELCOME MR. ";
    cout<<user.getFirstName()<<' '<<user.getLastName();
    Time time;
    gotoxy(85,4);
    Utility::setColor(1);
    time.displayTime();
    Utility::setColor(4);
    TextEffects text;
    text.typingText(string(" -: WELCOME :- "),53,4,10);
}
void Admin::admin_menu_program()
{
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        Utility::hidecursor();
        switch(key_counter)
        {
            case 0:
                gotoxy(69,8);
                wdg.label("-: USER DETAILS :-",Utility::WHITE,Utility::CYAN);
                gotoxy(14,8);
                wdg.label("-: PRODUCTS DETAILS :-",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    product_program();
                }
                break;
            case 1:
                gotoxy(14,8);
                wdg.label("-: PRODUCTS DETAILS :-",Utility::WHITE,Utility::CYAN);
                gotoxy(69,8);
                wdg.label("-: USER DETAILS :-",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    user_program();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_HOME)
                {
                    if(key==Utility::KEY_HOME)
                    {
                        MainMenu menu;
                        menu.main_menu_layout();
                        menu.main_menu_program();
                    }
                   else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
}
void Menu::show_discount()
{
    Widget wdg;
    int key_counter=0,input_validate=0;
    Utility::hidecursor();
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(47,18);
                wdg.label(" SNACKS ",Utility::WHITE,Utility::CYAN);
                gotoxy(12,18);
                wdg.label(" FAST FOOD ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    get_discount(1);
                }
                break;
            case 1:
                gotoxy(12,18);
                wdg.label(" FAST FOOD ",Utility::WHITE,Utility::CYAN);
                gotoxy(23,18);
                wdg.label(" ICE CREAM ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    get_discount(2);
                }
                break;
            case 2:
                gotoxy(23,18);
                wdg.label(" ICE CREAM ",Utility::WHITE,Utility::CYAN);
                gotoxy(34,18);
                wdg.label(" COLD DRINKS ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    get_discount(3);
                }
                break;
            case 3:
                gotoxy(34,18);
                wdg.label(" COLD DRINKS ",Utility::WHITE,Utility::CYAN);
                gotoxy(47,18);
                wdg.label(" SNACKS ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    get_discount(4);
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                            menu_program();
                   else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                    }
                }
                if(key_counter>3)
                    key_counter=0;
            }
        }
}
void Menu::menu_program()
{
    gotoxy(91,10);
    int key_counter=0,input_validate=0;
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    cout<<setfill(' ');
    cout<<setw(10)<<user.getBalance();
    gotoxy(69,8);
    Widget wdg;
    wdg.label("-: USER INFO :-",Utility::WHITE,Utility::CYAN);
    gotoxy(14,16);
    wdg.label("-: OFFERS :-",Utility::WHITE,Utility::CYAN);
    Utility::hidecursor();
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(69,19);
                wdg.label("-: MY ACCOUNT :-",Utility::WHITE,Utility::CYAN);
                gotoxy(14,8);
                wdg.label("-: ORDER FOOD :-",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    order_food();
                }
                break;
            case 1:
                gotoxy(14,8);
                wdg.label("-: ORDER FOOD :-",Utility::WHITE,Utility::CYAN);
                gotoxy(69,8);
                wdg.label("-: USER INFO :-",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    information();
                }
                break;
            case 2:
                gotoxy(69,8);
                wdg.label("-: USER INFO :-",Utility::WHITE,Utility::CYAN);
                gotoxy(14,16);
                wdg.label("-: OFFERS :-",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    show_discount();
                }
                break;
            case 3:
                gotoxy(14,16);
                wdg.label("-: OFFERS :-",Utility::WHITE,Utility::CYAN);
                gotoxy(69,19);
                wdg.label("-: MY ACCOUNT :-",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    my_account();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                    }
                }
                if(key_counter>3)
                    key_counter=0;
            }
        }
}
void Menu::view_details()
{
    Widget w;
    TextEffects text;
    w.dialogBox(" -: VIEW YOUR DETAILS :- ",25,5,90,26,Utility::BLACK,Utility::GREY);//25,5,90,26 //
    text.typingText(string(" -: VIEW YOUR DETAILS :- "),45,9,15);
    gotoxy(34,11);
    w.label("   FIRST NAME    :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(34,13);
    w.label("   LAST NAME     :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(34,15);
    w.label("     E-MAIL      :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(34,17);
    w.label("   CONTACT NO    :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(34,19);
    w.label("   DATE OF BIRTH :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(34,21);
    w.label("   CITY          :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(53,23);
    w.label("  DONE  ",Utility::BLACK,Utility::CYAN);
    Utility::setBackgroundColor(15);
    Utility::setColor(0);
    gotoxy(59,11);
    cout<<user.getFirstName();
    gotoxy(59,13);
    cout<<user.getLastName();
    gotoxy(59,15);
    cout<<user.getEmail();
    gotoxy(59,17);
    cout<<user.getContactNumber();
    gotoxy(59,19);
    cout<<user.getDateOfBirth();
    gotoxy(59,21);
    cout<<user.getCity();
    gotoxy(53,23);
    w.label("  DONE  ",Utility::RED,Utility::WHITE);
    getch();
    menu_layout();
    menu_program();
}
void Menu::log_out()
{
        Widget wdg;
        TextEffects text;
        Utility::hidecursor();
        wdg.dialogBox(" -: LOGOUT :- ",35,8,80,19,Utility::BLACK,Utility::GREY);
        Utility::setColor(15);
        text.typingText(string(" -: LOGOUT :- "),50,12,20);
        Utility::setColor(0);
        Utility::setBackgroundColor(Utility::GREY);
        gotoxy(46,14);
        cout<<" DO YOU WANT TO LOGOUT ";
        gotoxy(48,16);
        wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
        gotoxy(59,16);
        wdg.label(" LOGOUT ",Utility::BLACK,Utility::CYAN);
        int key_counter=0,input_validate=0;
        while(true)
        {
            switch(key_counter)
            {
                case 0:
                    gotoxy(59,16);
                    wdg.label(" LOGOUT ",Utility::WHITE,Utility::CYAN);
                    gotoxy(48,16);
                    wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                    if(input_validate==1)
                    {
                        input_validate=0;
                        menu_layout();
                        menu_program();
                    }
                    break;
                case 1:
                    gotoxy(48,16);
                    wdg.label(" CANCEL ",Utility::WHITE,Utility::CYAN);
                    gotoxy(59,16);
                    wdg.label(" LOGOUT ",Utility::RED,Utility::WHITE);
                    if(input_validate==2)
                    {
                        input_validate=0;
                        wdg.drawSolidBox(35,8,80,19,Utility::GREY);
                        wdg.drawBorderedBox(37,9,78,18,0,Utility::GREY);
                        Utility::setColor(0);
                        Utility::setBackgroundColor(Utility::GREY);
                        gotoxy(46,15);
                        cout<<"LOGING OUT YOUR ACCOUNT";
                        gotoxy(51,13);
                        Utility::hidecursor();
                        cout<<"LOGING OUT";
                        char dots[]="...";
                        for(char a:dots)
                        {
                            Sleep(1000);
                            cout<<a;
                        }
                        remove("ActiveUser.txt");
                        wdg.drawBorderedBox(37,9,78,18,0,Utility::GREY);
                        Utility::setColor(0);
                        Utility::setBackgroundColor(Utility::GREY);
                        gotoxy(45,15);
                        cout<<" LOGGED OUT SUCCESSFULLY";
                        gotoxy(51,13);
                        Utility::hidecursor();
                        cout<<"YOUR ACCOUNT";
                        Sleep(1000);
                        MainMenu menu;
                        menu.main_menu_layout();
                        menu.main_menu_program();
                    }
                    break;
                default:
                    break;
                }
                if(kbhit())
                {
                    int key = Utility::getkey();
                    if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                    {
                        if(key==Utility::KEY_TAB)
                            key_counter++;
                        else
                        {
                            if(key==Utility::KEY_ENTER&&key_counter==0)
                                input_validate++;
                            else if(key==Utility::KEY_ENTER&&key_counter==1)
                                input_validate+=2;
                        }
                    }
                    if(key_counter>1)
                        key_counter=0;
                }
            }

}
void Menu::edit_details()
{
    //borderedScreen();
    Widget w;
    TextEffects text;
     w.dialogBox(" -: EDIT YOUR DETAILS :- ",25,5,90,26,Utility::BLACK,Utility::GREY);//25,5,90,26 //
     text.typingText(string(" -: EDIT YOUR DETAILS :- "),45,9,15);
     gotoxy(30,12);
     w.label(" -> ",Utility::WHITE,Utility::CYAN);
    w.label("   FIRST NAME    :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(30,14);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    w.label("   LAST NAME     :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
     w.textBox(25);
    gotoxy(30,16);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    w.label("   CONTACT NO    :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(30,18);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    w.label("   DATE OF BIRTH :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(30,20);
    w.label(" -> ",Utility::WHITE,Utility::CYAN);
    w.label("   CITY          :",Utility::BLUE,Utility::GREY);
    cout<<'\t';
    w.textBox(25);
    gotoxy(53,23);
    w.label("  DONE  ",Utility::BLACK,Utility::CYAN);
    Utility::setBackgroundColor(15);
    Utility::setColor(0);
    gotoxy(59,12);
    cout<<user.getFirstName();
    gotoxy(59,14);
    cout<<user.getLastName();
    gotoxy(59,16);
    cout<<user.getContactNumber();
    gotoxy(59,18);
    cout<<user.getDateOfBirth();
    gotoxy(59,20);
    cout<<user.getCity();
    Utility::hidecursor();
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(53,23);
                wdg.label("  DONE  ",Utility::BLACK,Utility::CYAN);
                gotoxy(30,12);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    gotoxy(57,12);
                    w.textBox(25);
                    gotoxy(59,12);
                    Utility::showcursor();
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    string temp;
                    cin>>temp;
                    ofstream file;
                    string email = user.getEmail();
                    UserData usertemp;
                    file.open("temp.txt");
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                        {
                            usertemp.setFirstName(temp);
                            user=usertemp;
                        }
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    convertTempFile();
                    updateFile();
                    wdg.alertBox("First Name Updated Successfully",38,10,77,19,Utility::BLACK,Utility::WHITE);
                    Utility::hidecursor();
                    edit_details();
                }
                break;
            case 1:
                gotoxy(30,12);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(30,14);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    gotoxy(57,14);
                    w.textBox(25);
                    gotoxy(59,14);
                    Utility::showcursor();
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    string temp;
                    cin>>temp;
                    ofstream file;
                    string email = user.getEmail();
                    UserData usertemp;
                    file.open("temp.txt");
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                        {
                            usertemp.setLastName(temp);
                            user=usertemp;
                        }
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    convertTempFile();
                    updateFile();
                    wdg.alertBox("Last Name Updated Successfully",38,10,77,19,Utility::BLACK,Utility::WHITE);
                    Utility::hidecursor();
                    edit_details();
                }
                break;
            case 2:
                gotoxy(30,14);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(30,16);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    gotoxy(57,16);
                    w.textBox(25);
                    gotoxy(59,16);
                    Utility::showcursor();
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    string temp;
                    cin>>temp;
                    ofstream file;
                    string email = user.getEmail();
                    UserData usertemp;
                    file.open("temp.txt");
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                        {
                            usertemp.setContactNumber(temp);
                            user=usertemp;
                        }
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    convertTempFile();
                    updateFile();
                    wdg.alertBox("Contact No. Updated Successfully",38,10,77,19,Utility::BLACK,Utility::WHITE);
                    Utility::hidecursor();
                    edit_details();
                }
                break;
            case 3:
                gotoxy(30,16);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(30,18);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    gotoxy(57,18);
                    w.textBox(25);
                    gotoxy(59,18);
                    Utility::showcursor();
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    string temp;
                    cin>>temp;
                    ofstream file;
                    string email = user.getEmail();
                    UserData usertemp;
                    file.open("temp.txt");
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                        {
                            usertemp.setDateOfBirth(temp);
                            user=usertemp;
                        }
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    convertTempFile();
                    updateFile();
                    wdg.alertBox(" DOB Updated Successfully",38,10,77,19,Utility::BLACK,Utility::WHITE);
                    Utility::hidecursor();
                    edit_details();

                }
                break;
            case 4:
                gotoxy(30,18);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(30,20);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==5)
                {
                    input_validate=0;
                    gotoxy(57,20);
                    w.textBox(25);
                    gotoxy(59,20);
                    Utility::showcursor();
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    string temp;
                    cin>>temp;
                    ofstream file;
                    string email = user.getEmail();
                    UserData usertemp;
                    file.open("temp.txt");
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                        {
                            usertemp.setCity(temp);
                            user=usertemp;
                        }
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    file.open("UserData.txt");
                    file1.open("temp.txt");
                    while(file1>>usertemp)
                    {
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    convertTempFile();
                    updateFile();
                    wdg.alertBox(" City Updated Successfully",38,10,77,19,Utility::BLACK,Utility::WHITE);
                    Utility::hidecursor();
                    edit_details();

                }
                break;
            case 5:
                gotoxy(30,20);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(53,23);
                wdg.label("  DONE  ",Utility::RED,Utility::WHITE);
                if(input_validate==6)
                {
                    input_validate=0;
                    menu_layout();
                    menu_program();

                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                        else if(key==Utility::KEY_ENTER&&key_counter==4)
                            input_validate+=5;
                        else if(key==Utility::KEY_ENTER&&key_counter==5)
                            input_validate+=6;
                    }
                }
                if(key_counter>5)
                    key_counter=0;
            }
        }


}
void Menu::information()
{
    Utility::hidecursor();
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(69,14);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(69,12);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    view_transactions();
                }
                break;
            case 1:
                gotoxy(69,12);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(69,14);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    gotoxy(92,14);
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    long int balance=user.getBalance();
                    long int add,prev=balance;
                    Utility::showcursor();
                    cin>>add;
                    if(add<100)
                    {
                        wdg.alertBox("Amount Must Be Greater Than RS 100",35,8,80,17,0,15);
                        menu_layout();
                        menu_program();
                    }
                    balance+=add;
                    Utility::hidecursor();
                    gotoxy(103,14);
                    wdg.label(" + ",Utility::RED,Utility::YELLOW);
                    user.setBalance(balance);
                    getch();
                    ofstream file("ActiveUser.txt");
                    file<<user;
                    file.close();
                    UserData usertemp;
                    file.open("temp.txt");
                    string email=user.getEmail();
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                            usertemp.setBalance(balance);
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    remove("UserData.txt");
                    rename("temp.txt","UserData.txt");
                    Transaction trans;
                    ofstream fout;
                    ifstream fin;
                    fin.open("srno1.txt");
                    fin>>trans.srno;
                    fin.close();
                    trans.srno++;
                    fout.open("srno1.txt");
                    fout<<trans.srno;
                    fout.close();
                    trans.email=user.getEmail();
                    trans.amount=add;
                    trans.previous_balance=prev;
                    trans.final_amt=prev+add;
                    fout.open("Transactions.txt",ios::app);
                    fout<<trans;
                    fout.close();
                    Utility::hidecursor();
                    borderedScreen();
                    TextEffects text;
                    wdg.dialogBox(" -: ADD BALANCE :- ",30,6,85,21,Utility::BLACK,Utility::GREY);
                    text.typingText(string(" -: BALANCE ADDED SUCCESSFULLY :- "),40,10,20);
                    gotoxy(37,12);
                    wdg.label(" PREVIOUS BALANCE ::: ",Utility::BLACK,Utility::GREY);
                    gotoxy(60,12);
                    wdg.textBox(17);
                    gotoxy(37,14);
                    wdg.label(" BALANCE ADDED    ::: ",Utility::BLACK,Utility::GREY);
                    gotoxy(60,14);
                    wdg.textBox(17);
                    gotoxy(37,16);
                    wdg.label(" NEW BALANCE      ::: ",Utility::BLACK,Utility::GREY);
                    gotoxy(60,16);
                    wdg.textBox(17);
                    gotoxy(43,18);
                    wdg.label(" PRESS ANY KEY TO CONTINUE ",Utility::RED,Utility::WHITE);
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    gotoxy(61,12);
                    cout<<"RS"<<setw(12)<<prev;
                    gotoxy(61,14);
                    cout<<"RS"<<setw(12)<<add;
                    gotoxy(61,16);
                    cout<<"RS"<<setw(12)<<balance;
                    gotoxy(68,18);
                    getch();
                    menu_layout();
                    menu_program();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                    {
                        menu_program();
                    }
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
}
void Menu::change_password()
{
    //borderedScreen();
    Widget wdg;
    TextEffects text;
        Utility::hidecursor();
        wdg.dialogBox(" -: CHANGE PASSWORD :- ",30,6,85,21,Utility::BLACK,Utility::GREY);
        text.typingText(string(" -: CHANGE PASSWORD :- "),46,10,20);
        gotoxy(37,12);
        wdg.label("CURRENT PASSWORD ::: ",Utility::BLACK,Utility::GREY);
        gotoxy(60,12);
        wdg.textBox(17);
        gotoxy(37,14);
        wdg.label("NEW PASSWORD     ::: ",Utility::BLACK,Utility::GREY);
        gotoxy(60,14);
        wdg.textBox(17);
        gotoxy(37,16);
        wdg.label("CONFIRM PASSWORD ::: ",Utility::BLACK,Utility::GREY);
        gotoxy(60,16);
        wdg.textBox(17);
        gotoxy(48,18);
        wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
        gotoxy(59,18);
        wdg.label(" CHANGE ",Utility::BLACK,Utility::CYAN);
        string current;
        string new_pass;
        string conf_pass;
        Utility::showcursor();
        gotoxy(61,12);
        Utility::setColor(0);
        Utility::setBackgroundColor(15);
        current=wdg.getEncryptedText();
        if(current!=user.getPassword())
        {
                wdg.alertBox(" ENTER VALID PASSWORD ",38,10,77,19,Utility::BLACK,Utility::WHITE);
                change_password();
        }
        gotoxy(61,14);
        new_pass=wdg.getEncryptedText();
        if(new_pass.size()<8)
        {
                wdg.alertBox(" ENTER MIN 8 CHARACTERS",38,10,77,19,Utility::BLACK,Utility::WHITE);
                change_password();
        }
        gotoxy(61,16);
        conf_pass=wdg.getEncryptedText();
        if(new_pass!=conf_pass)
        {
                wdg.alertBox(" PASSWORD NOT MATCHED ",38,10,77,19,Utility::BLACK,Utility::WHITE);
                change_password();
        }
        int key_counter=0,input_validate=0;
        Utility::hidecursor();
        while(true)
        {
            switch(key_counter)
            {
            case 0:
                gotoxy(59,18);
                wdg.label(" CHANGE ",Utility::BLACK,Utility::CYAN);
                gotoxy(48,18);
                wdg.label(" CANCEL ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    menu_layout();
                    menu_program();
                }
                break;
            case 1:
                gotoxy(48,18);
                wdg.label(" CANCEL ",Utility::BLACK,Utility::CYAN);
                gotoxy(59,18);
                wdg.label(" CHANGE ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    ofstream file;
                    string email = user.getEmail();
                    UserData usertemp;
                    file.open("temp.txt");
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                        {
                            usertemp.setPassword(conf_pass);
                            user=usertemp;
                        }
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    file.open("UserData.txt");
                    file1.open("temp.txt");
                    while(file1>>usertemp)
                    {
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
                    convertTempFile();
                    updateFile();
                    wdg.alertBox(" Password Changed Successfully",38,10,77,19,Utility::BLACK,Utility::WHITE);
                    Utility::hidecursor();
                    menu_layout();
                    menu_program();

                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }



}
void Menu::my_account()
{
    Utility::hidecursor();
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(92,24);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(68,21);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    borderedScreen();
                    view_details();
                }
                break;
            case 1:
                gotoxy(68,21);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(68,24);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    borderedScreen();
                    change_password();
                }
                break;
            case 2:
                gotoxy(68,24);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(92,21);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    borderedScreen();
                    edit_details();
                    exit(0);

                }
                break;
            case 3:
                gotoxy(92,21);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(92,24);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    borderedScreen();
                    log_out();

                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                    {
                        menu_program();
                    }
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                    }
                }
                if(key_counter>3)
                    key_counter=0;
            }
        }
}
void OrderMenu::order_menu_layout()
{
    Widget wdg;
    Shape shape;
    Utility::hidecursor();
    shape.drawSolidBox(7,2,115,5,7);
    shape.drawBorderedBox(9,2,113,5,0,7);
    wdg.dialogBox(" -: BUY PRODUCTS :- ",7,6,60,27,Utility::BLACK,Utility::GREY);
    wdg.dialogBox(" -: BILL :- ",62,6,115,27,Utility::BLACK,Utility::GREY);
    shape.drawSolidBox(65,9,112,23,15);
    gotoxy(20,10);
    wdg.label("  FAST FOOD  ",15,3);
    gotoxy(35,10);
    wdg.label(" COLD DRINKS ",15,3);
    gotoxy(20,12);
    wdg.label("  ICE CREAM  ",15,3);
    gotoxy(35,12);
    wdg.label("   SNACKS    ",15,3);
    gotoxy(17,14);
    wdg.label("PRODUCT ",Utility::BLUE,Utility::GREY);
    gotoxy(29,14);
    wdg.label("AVL",Utility::BLUE,Utility::GREY);
    gotoxy(35,14);
    wdg.label("QUANTITY ",Utility::BLUE,Utility::GREY);
    gotoxy(45,14);
    wdg.label("PRICE  ",Utility::BLUE,Utility::GREY);
    gotoxy(12,16);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
//    gotoxy(18,16);
//    wdg.label("NAME",Utility::BLUE,Utility::GREY);
    gotoxy(29,16);
    wdg.textBox(4);
    gotoxy(37,16);
    wdg.textBox(4);
    gotoxy(45,16);
    wdg.textBox(4);
    gotoxy(52,16);
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(12,18);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
//    gotoxy(18,18);
//    wdg.label("NAME",Utility::BLUE,Utility::GREY);
    gotoxy(29,18);
    wdg.textBox(4);
    gotoxy(37,18);
    wdg.textBox(4);
    gotoxy(45,18);
    wdg.textBox(4);
    gotoxy(52,18);
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(12,20);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
//    gotoxy(18,20);
//    wdg.label("NAME",Utility::BLUE,Utility::GREY);
    gotoxy(29,20);
    wdg.textBox(4);
    gotoxy(37,20);
    wdg.textBox(4);
    gotoxy(45,20);
    wdg.textBox(4);
    gotoxy(52,20);
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(12,22);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
//    gotoxy(18,22);
//    wdg.label("NAME",Utility::BLUE,Utility::GREY);
    gotoxy(29,22);
    wdg.textBox(4);
    gotoxy(37,22);
    wdg.textBox(4);
    gotoxy(45,22);
    wdg.textBox(4);
    gotoxy(52,22);
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
    gotoxy(12,24);
    wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
//    gotoxy(18,24);
//    wdg.label("NAME",Utility::BLUE,Utility::GREY);
    gotoxy(29,24);
    wdg.textBox(4);
    gotoxy(37,24);
    wdg.textBox(4);
    gotoxy(45,24);
    wdg.textBox(4);
    gotoxy(52,24);
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    gotoxy(66,13);
    for(int i=66;i<111;i++)
        cout<<char(196);
    Utility::setColor(Utility::GREEN);
    gotoxy(67,11);
    cout<<"NAME:";
    gotoxy(90,11);
    cout<<"DATE:";
    gotoxy(67,12);
    cout<<"PRODUCT";
    gotoxy(80,12);
    cout<<"QUANTITY";
    gotoxy(90,12);
    cout<<"DISCOUNT";
    gotoxy(103,12);
    cout<<"PRICE";
    gotoxy(66,21);
    for(int i=66;i<111;i++)
        cout<<char(196);
    gotoxy(90,22);
    cout<<"TOTAL: RS ";
    gotoxy(84,25);
    wdg.label(" PAY NOW ",15,3);
    Utility::setColor(1);
    Utility::setBackgroundColor(7);
    gotoxy(12,4);
    cout<<" WELCOME MR. ";
    cout<<user.getFirstName()<<' '<<user.getLastName();
    Time time;
    gotoxy(85,4);
    Utility::setColor(1);
    time.displayTime();
    gotoxy(73,11);
    Utility::setColor(0);
    Utility::setBackgroundColor(15);
    cout<<user.getFirstName()<<' '<<user.getLastName();
    gotoxy(97,11);
    cout<<time.getDate()<<'/'<<time.getMonth()<<'/'<<time.getYear();
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    TextEffects text;
    text.typingText(string(" -: WELCOME :- "),53,4,10);

}
void OrderMenu::order_menu_program()
{
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(69,8);
                wdg.label("-: BILL :-",Utility::WHITE,Utility::CYAN);
                gotoxy(14,8);
                wdg.label("-: BUY PRODUCTS :-",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    product_catagory();
                }
                break;
            case 1:
                gotoxy(14,8);
                wdg.label("-: BUY PRODUCTS :-",Utility::WHITE,Utility::CYAN);
                gotoxy(69,8);
                wdg.label("-: BILL :-",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    pay_now();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER)
                {
                    if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
}
void OrderMenu::pay_now()
{
    Widget wdg;
    Utility::setColor(4);
    Utility::setBackgroundColor(15);
    gotoxy(84,25);
    wdg.label(" PAY NOW ",4,15);
    getch();
    ofstream fout("Orders.txt",ios::app);
    ifstream fin("Cart.txt");
    int q,pr,dis;
    string name;
    int total=0;
    Order order;
    ifstream fin1("srno.txt");
    fin1>>order.srno;
    fin1.close();
    int prev = user.getBalance();
    while(fin>>name>>q>>dis>>pr)
    {
        order.srno++;
        order.email=user.getEmail();
        order.name = user.getFirstName();
        order.price=pr;
        order.product=name;
        order.quantity=q;
        total+=pr;
        fout<<order;
    }
    ofstream fout1("srno.txt");
    fout1<<order.srno;
    fout1.close();
    fin.close();
    fout.close();
    if(user.getBalance()<total)
    {
        wdg.alertBox(" YOU DO NOT HAVE ENOUGH BALANCE",35,8,80,17,0,15);
        Menu menu;
        menu.menu_layout();
        menu.menu_program();
    }
    user.setBalance(user.getBalance()-total);
    ofstream file;
                    string email = user.getEmail();
                    UserData usertemp;
                    file.open("temp.txt");
                    ifstream file1("UserData.txt");
                    while(file1>>usertemp)
                    {
                        if(email==usertemp.getEmail())
                        {
                            usertemp.setBalance(user.getBalance());
                            user=usertemp;
                        }
                        file<<usertemp;
                    }
                    file.close();
                    file1.close();
        updateFile();
        convertTempFile();
        remove("Cart.txt");
        Transaction trans;
        fin.open("srno1.txt");
        fin>>trans.srno;
        fin.close();
        trans.srno++;
        fout.open("srno1.txt");
        fout<<trans.srno;
        fout.close();
        trans.email=user.getEmail();
        trans.amount=total;
        trans.previous_balance=prev;
        trans.final_amt=prev-total;
        fout.open("Transactions.txt",ios::app);
        fout<<trans;
        fout.close();
        borderedScreen();
        wdg.drawSolidBox(35,8,80,19,Utility::GREY);
                        wdg.drawBorderedBox(37,9,78,18,0,Utility::GREY);
                        Utility::setColor(0);
                        Utility::setBackgroundColor(Utility::GREY);
                        gotoxy(43 ,15);
                        cout<<"TRANSACTION IS BEING PROCESSED";
                        gotoxy(53,13);
                        Utility::hidecursor();
                        cout<<"LOADING";
                        char dots[]="...";
                        for(char a:dots)
                        {
                            Sleep(1000);
                            cout<<a;
                        }
                    TextEffects text;
                    wdg.dialogBox(" -: SUMMARY :- ",30,6,85,21,Utility::BLACK,Utility::GREY);
                    text.typingText(string(" -: ORDER PLACED SUCCESSFULLY :- "),40,10,20);
                    gotoxy(37,12);
                    wdg.label(" PREVIOUS BALANCE ::: ",Utility::BLACK,Utility::GREY);
                    gotoxy(60,12);
                    wdg.textBox(17);
                    gotoxy(37,14);
                    wdg.label(" AMOUNT DEDUCTED  ::: ",Utility::BLACK,Utility::GREY);
                    gotoxy(60,14);
                    wdg.textBox(17);
                    gotoxy(37,16);
                    wdg.label(" NEW BALANCE      ::: ",Utility::BLACK,Utility::GREY);
                    gotoxy(60,16);
                    wdg.textBox(17);
                    gotoxy(43,18);
                    wdg.label(" PRESS ANY KEY TO CONTINUE ",Utility::RED,Utility::WHITE);
                    Utility::setColor(0);
                    Utility::setBackgroundColor(15);
                    gotoxy(61,12);
                    cout<<"RS"<<setw(12)<<prev;
                    gotoxy(61,14);
                    cout<<"RS"<<setw(12)<<total;
                    gotoxy(61,16);
                    cout<<"RS"<<setw(12)<<user.getBalance();
                    gotoxy(68,18);
                    getch();
                    Menu menu;
                    menu.menu_layout();
                    menu.menu_program();
}
void OrderMenu::product(int catatory)
{
    string products[4][5];
    products[0][0]="PIZZA";
    products[0][1]="BURGER";
    products[0][2]="SANDWITCH";
    products[0][3]="VADAPAV";
    products[0][4]="DABELI";
    products[1][4]="CHOCOCHIPS";
    products[1][0]="VANILLA";
    products[1][1]="CHOCOLATE";
    products[1][2]="STRAWBERRY";
    products[1][3]="RAJBHOG";
    products[2][0]="PEPSI";
    products[2][1]="MOUNT.DEW";
    products[2][2]="THUMBS_UP";
    products[2][3]="SLICE";
    products[2][4]="SPRITE";
    products[3][0]="LAYS";
    products[3][1]="KUKURE";
    products[3][2]="SOLID_MASTI";
    products[3][3]="OREO";
    products[3][4]="CHEETOS";

    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(12,24);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(12,16);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    getData(catatory,1,products[catatory-1][0]);
                }
                break;
            case 1:
                gotoxy(12,16);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(12,18);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    getData(catatory,2,products[catatory-1][1]);
                }
                break;
            case 2:
                gotoxy(12,18);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(12,20);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    getData(catatory,3,products[catatory-1][2]);
                }
                break;
            case 3:
                gotoxy(12,20);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(12,22);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    getData(catatory,4,products[catatory-1][3]);
                }
                break;
            case 4:
                gotoxy(12,22);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(12,24);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==5)
                {
                    input_validate=0;
                    getData(catatory,5,products[catatory-1][4]);
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                        product_catagory();
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                        else if(key==Utility::KEY_ENTER&&key_counter==4)
                            input_validate+=5;
                    }
                }
                if(key_counter>4)
                    key_counter=0;
            }
        }
}
void OrderMenu::product_catagory()
{
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(35,12);
                wdg.label("   SNACKS    ",Utility::WHITE,Utility::CYAN);
                gotoxy(20,10);
                wdg.label("  FAST FOOD  ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    clear_products();
                    fast_food();
                    product(1);
                }
                break;
            case 1:
                gotoxy(20,10);
                wdg.label("  FAST FOOD  ",Utility::WHITE,Utility::CYAN);
                gotoxy(20,12);
                wdg.label("  ICE CREAM  ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    clear_products();
                    ice_cream();
                    product(2);
                }
                break;
            case 2:
                gotoxy(20,12);
                wdg.label("  ICE CREAM  ",Utility::WHITE,Utility::CYAN);
                gotoxy(35,10);
                wdg.label(" COLD DRINKS ",Utility::RED,Utility::WHITE);
                if(input_validate==3)
                {
                    input_validate=0;
                    clear_products();
                    cold_drinks();
                    product(3);
                }
                break;
            case 3:
                gotoxy(35,10);
                wdg.label(" COLD DRINKS ",Utility::WHITE,Utility::CYAN);
                gotoxy(35,12);
                wdg.label("   SNACKS    ",Utility::RED,Utility::WHITE);
                if(input_validate==4)
                {
                    input_validate=0;
                    clear_products();
                    snacks();
                    product(4);
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                        order_menu_program();
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                        else if(key==Utility::KEY_ENTER&&key_counter==2)
                            input_validate+=3;
                        else if(key==Utility::KEY_ENTER&&key_counter==3)
                            input_validate+=4;
                    }
                }
                if(key_counter>3)
                    key_counter=0;
            }
        }
}
void Menu::order_food()
{
    Widget wdg;
    int key_counter=0,input_validate=0;
    while(true)
    {
        switch(key_counter)
        {
            case 0:
                gotoxy(30,10);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(12,10);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==1)
                {
                    input_validate=0;
                    OrderMenu order;
                    order.order_menu_layout();
                    order.order_menu_program();
                }
                break;
            case 1:
                gotoxy(12,10);
                wdg.label(" -> ",Utility::WHITE,Utility::CYAN);
                gotoxy(30,10);
                wdg.label(" -> ",Utility::RED,Utility::WHITE);
                if(input_validate==2)
                {
                    input_validate=0;
                    view_recent_orders();
                }
                break;
            default:
                break;
            }
            if(kbhit())
            {
                int key = Utility::getkey();
                if(key==Utility::KEY_TAB||key==Utility::KEY_ENTER||key==Utility::KEY_ESCAPE)
                {
                    if(key==Utility::KEY_ESCAPE)
                        menu_program();
                    else if(key==Utility::KEY_TAB)
                        key_counter++;
                    else
                    {
                        if(key==Utility::KEY_ENTER&&key_counter==0)
                            input_validate++;
                        else if(key==Utility::KEY_ENTER&&key_counter==1)
                            input_validate+=2;
                    }
                }
                if(key_counter>1)
                    key_counter=0;
            }
        }
}
void Menu::get_discount(int catagory_code)
{
    clear_space();
    string products[4][5];
    products[0][0]="PIZZA";
    products[0][1]="BURGER";
    products[0][2]="SANDWITCH";
    products[0][3]="VADAPAV";
    products[0][4]="DABELI";
    products[1][4]="CHOCOCHIPS";
    products[1][0]="VANILLA";
    products[1][1]="CHOCOLATE";
    products[1][2]="STRAWBERRY";
    products[1][3]="RAJBHOG";
    products[2][0]="PEPSI";
    products[2][1]="MOUNT.DEW";
    products[2][2]="THUMBS_UP";
    products[2][3]="SLICE";
    products[2][4]="SPRITE";
    products[3][0]="LAYS";
    products[3][1]="KUKURE";
    products[3][2]="SOLID_MASTI";
    products[3][3]="OREO";
    products[3][4]="CHEETOS";
    Utility::setBackgroundColor(7);
    Utility::setColor(0);
    int yco=21;
    for(int i=0;i<5;i++)
    {
        gotoxy(15,yco);
        cout<<products[catagory_code-1][i];
        yco++;
    }
    ifstream fin("Products.txt");
    Product p;
    int y=21;
    cout<<setfill(' ');
    while(fin>>p)
    {
        if(p.getCatagoryCode()==catagory_code)
        {
            gotoxy(30,y);cout<<setw(3)<<p.getDiscount()<<"%";
            gotoxy(45,y);cout<<setw(3)<<p.getQuantity();
            y++;
        }
    }
    fin.close();
}
void OrderMenu::fast_food()
{
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(18,16);
    cout<<"PIZZA";
    gotoxy(18,18);
    cout<<"BURGER";
    gotoxy(18,20);
    cout<<"SANDWITCH";
    gotoxy(18,22);
    cout<<"VADAPAV";
    gotoxy(18,24);
    cout<<"DABELI";
    ifstream fin("Products.txt");
    Product p;
    int y=16;
    Utility::setBackgroundColor(15);
    cout<<setfill(' ');
    while(fin>>p)
    {
        if(p.getCatagoryCode()==1)
        {
            gotoxy(29,y);cout<<setw(3)<<p.getQuantity();
            gotoxy(45,y);cout<<setw(3)<<p.getPrice();
            y+=2;
        }
    }
    fin.close();
}
void OrderMenu::ice_cream()
{
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(18,16);
    cout<<"VANILLA";
    gotoxy(18,18);
    cout<<"CHOCOLATE";
    gotoxy(18,20);
    cout<<"STRAWBERRY";
    gotoxy(18,22);
    cout<<"RAJBHOG";
    gotoxy(18,24);
    cout<<"CHOCOCHIPS";
    ifstream fin("Products.txt");
    Product p;
    int y=16;
    Utility::setBackgroundColor(15);
    cout<<setfill(' ');
    while(fin>>p)
    {
        if(p.getCatagoryCode()==2)
        {
            gotoxy(29,y);cout<<setw(3)<<p.getQuantity();
            gotoxy(45,y);cout<<setw(3)<<p.getPrice();
            y+=2;
        }
    }
    fin.close();
}
void OrderMenu::cold_drinks()
{
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(18,16);
    cout<<"PEPSI";
    gotoxy(18,18);
    cout<<"MOUNT. DEW";
    gotoxy(18,20);
    cout<<"THUMBS UP";
    gotoxy(18,22);
    cout<<"SLICE";
    gotoxy(18,24);
    cout<<"SPRITE";
    ifstream fin("Products.txt");
    Product p;
    int y=16;
    Utility::setBackgroundColor(15);
    cout<<setfill(' ');
    while(fin>>p)
    {
        if(p.getCatagoryCode()==3)
        {
            gotoxy(29,y);cout<<setw(3)<<p.getQuantity();
            gotoxy(45,y);cout<<setw(3)<<p.getPrice();
            y+=2;
        }
    }
    fin.close();
}
void OrderMenu::snacks()
{
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(18,16);
    cout<<"LAYS";
    gotoxy(18,18);
    cout<<"KURKURE";
    gotoxy(18,20);
    cout<<"SOLID MASTI";
    gotoxy(18,22);
    cout<<"OREO";
    gotoxy(18,24);
    cout<<"CHEETOS";
    ifstream fin("Products.txt");
    Product p;
    int y=16;
    Utility::setBackgroundColor(15);
    cout<<setfill(' ');
    while(fin>>p)
    {
        if(p.getCatagoryCode()==4)
        {
            gotoxy(29,y);cout<<setw(3)<<p.getQuantity();
            gotoxy(45,y);cout<<setw(3)<<p.getPrice();
            y+=2;
        }
    }
    fin.close();
}
void OrderMenu::getData(int catagory,int product,string product_name)
{
    price=0;
    quantity=0;
    Widget wdg;
    int y = product*2;
    y+=14;
    error:
    Utility::setColor(4);
    Utility::setBackgroundColor(15);
    gotoxy(38,y);
    Utility::showcursor();
    cin>>quantity;
    Utility::hidecursor();
    this->product_name=product_name;
    ifstream fin("Products.txt");
    Product p;
    while(fin>>p)
    {
        if(p.getCatagoryCode()==catagory&&p.getProductCode()==product)
            break;
    }
    fin.close();
    if(quantity>p.getQuantity()||quantity<0)
    {
        Utility::setColor(15);
        Utility::setBackgroundColor(4);
        gotoxy(30,15);
        cout<<"Enter Valid Quantity";
        gotoxy(37,y);
        wdg.textBox(3);
        goto error;
    }
    gotoxy(52,y);
    wdg.label(" + ",Utility::RED,Utility::WHITE);
    getch();
    price+=quantity*p.getPrice();
    int discount=price*p.getDiscount()/100;
    price-=discount;
    ofstream fout("Cart.txt",ios::app);
    fout<<product_name<<space<<quantity<<space<<p.getDiscount()<<space<<price<<endl;
    fout.close();
    fin.open("Cart.txt");
    int q,pr,dis,total_price=0;
    string name;
    int i=14;
    while(fin>>name>>q>>dis>>pr)
    {
        gotoxy(67,i);cout<<name;
        gotoxy(82,i);cout<<q<<"Nos.";
        gotoxy(92,i);cout<<dis<<'%';
        gotoxy(103,i);cout<<"RS "<<pr;
        total_price+=pr;
        i+=1;
    }
    fin.close();
    gotoxy(100,22);
    cout<<total_price;
    fin.open("Products.txt");
    fout.open("temp.txt");
    while(fin>>p)
    {
        if(p.getCatagoryCode()==catagory&&p.getProductCode()==product)
            p.setQuantity(p.getQuantity()-quantity);
        fout<<p;
    }
    fin.close();
    fout.close();
    fin.open("temp.txt");
    fout.open("Products.txt");
    while(fin>>p)
        fout<<p;
    fin.close();
    fout.close();
    remove("temp.txt");
    switch(catagory)
    {
    case 1:
        fast_food();
        break;
    case 2:
        ice_cream();
        break;
    case 3:
        cold_drinks();
        break;
    case 4:
        snacks();
        break;
    }
    gotoxy(52,y);
    wdg.label(" + ",Utility::WHITE,Utility::CYAN);
    Utility::setBackgroundColor(7);
    gotoxy(30,15);
    for(int i=0;i<20;i++)cout<<" ";
}
void OrderMenu::clear_products()
{
    Widget wdg;
    for(int i=16;i<26;i+=2)
    {
        Utility::setBackgroundColor(7);
        gotoxy(18,i);
        cout<<"           ";
        gotoxy(29,i);
        wdg.textBox(4);
        gotoxy(37,i);
        wdg.textBox(4);
        gotoxy(45,i);
        wdg.textBox(4);
        gotoxy(52,i);
    }

}
class System:public StartPage,public Login,public MainMenu{};
void Menu::view_transactions()
{
    Widget wdg;
    Utility::hidecursor();
    borderedScreen();
    wdg.dialogBox(" -: VIEW TRANSACTIONS :- ",15,3,105,26,0,7);
    TextEffects txefft;
    txefft.typingText(string(" -: TRANSACTIONS :- "),50,7,20);
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(25,9);
    cout<<" DATE ";
    gotoxy(35,9);
    cout<<" TIME ";
    gotoxy(44,9);
    cout<<" PREV. AMOUNT ";
    gotoxy(61,9);
    cout<<" TYPE ";
    gotoxy(70,9);
    cout<<" TRANS. AMOUNT ";
    gotoxy(85,9);
    cout<<" FINAL AMOUNT ";
    Transaction order;
    string email=user.getEmail();
    ifstream fin("Transactions.txt");
    int y=11;
    string type;
    Utility::setColor(0);
    while(fin>>order)
    {
        if(email==order.email)
        {
            if(order.final_amt>order.previous_balance)
                type="Cr";
            else if(order.final_amt<order.previous_balance)
                    type="Dr";
            gotoxy(24,y);
            cout<<order.day<<'/'<<order.month<<'/'<<order.year;
            gotoxy(35,y);
            cout<<order.hour<<':'<<order.minute<<ends<<order.suffix;
            gotoxy(47,y);
            cout<<"RS "<<order.previous_balance;
            gotoxy(63,y);
            cout<<type;
            gotoxy(74,y);
            cout<<"RS "<<order.amount;
            gotoxy(86,y);
            cout<<"RS "<<order.final_amt;
            y++;
            if(y>22)
            {
                gotoxy(55,24);
                wdg.label(" NEXT PAGE ",4,15);
                getch();
                wdg.dialogBox(" -: VIEW TRANSACTIONS :- ",15,3,105,26,0,7);
                txefft.typingText(string(" -: TRANSACTIONS :- "),50,7,20);
                Utility::setBackgroundColor(7);
                Utility::setColor(4);
                gotoxy(25,9);
                cout<<" DATE ";
                gotoxy(35,9);
                cout<<" TIME ";
                gotoxy(44,9);
                cout<<" PREV. AMOUNT ";
                gotoxy(61,9);
                cout<<" TYPE ";
                gotoxy(70,9);
                cout<<" TRANS. AMOUNT ";
                gotoxy(85,9);
                cout<<" FINAL AMOUNT ";
                Utility::setColor(0);
                y=11;
            }
        }
    }
    gotoxy(55,y+1);
    wdg.label(" MAIN MENU ",4,15);
    getch();
    fin.close();
    menu_layout();
    menu_program();
}
void Menu::view_recent_orders()
{
    Widget wdg;
    Utility::hidecursor();
    borderedScreen();
    wdg.dialogBox(" -: VIEW RECENT ORDERS :- ",15,3,105,26,0,7);
    TextEffects txefft;
    txefft.typingText(string(" -: RECENT ORDERS :- "),50,7,20);
    Utility::setBackgroundColor(7);
    Utility::setColor(4);
    gotoxy(25,9);
    cout<<" DATE ";
    gotoxy(37,9);
    cout<<" TIME ";
    gotoxy(50,9);
    cout<<" PRODUCT NAME ";
    gotoxy(68,9);
    cout<<" QUANTITY ";
    gotoxy(85,9);
    cout<<" AMOUNT ";
    Order order;
    string email=user.getEmail();
    ifstream fin("Orders.txt");
    int y=11;
    Utility::setColor(0);
    while(fin>>order)
    {
        if(email==order.email)
        {
            gotoxy(24,y);
            cout<<setfill('0');
            cout<<setw(2)<<order.day<<'/'<<setw(2)<<order.month<<'/'<<order.year;
            gotoxy(37,y);
            cout<<setw(2)<<order.hour<<':'<<setw(2)<<order.minute<<ends<<order.suffix;
            gotoxy(52,y);
            cout<<order.product;
            gotoxy(72,y);
            cout<<order.quantity;
            gotoxy(86,y);
            cout<<"RS "<<order.price;
            y++;
            if(y>22)
            {
                gotoxy(55,24);
                wdg.label(" NEXT PAGE ",4,15);
                getch();
                wdg.dialogBox(" -: VIEW RECENT ORDERS :- ",15,3,105,26,0,7);
                txefft.typingText(string(" -: RECENT ORDERS :- "),50,7,20);
                Utility::setBackgroundColor(7);
                Utility::setColor(4);
                gotoxy(25,9);
                cout<<" DATE ";
                gotoxy(37,9);
                cout<<" TIME ";
                gotoxy(50,9);
                cout<<" PRODUCT NAME ";
                gotoxy(68,9);
                cout<<" QUANTITY ";
                gotoxy(85,9);
                cout<<" AMOUNT ";
                Utility::setColor(0);
                y=11;
            }
        }
    }
    gotoxy(55,y+1);
    wdg.label(" MAIN MENU ",4,15);
    getch();
    fin.close();
    menu_layout();
    menu_program();
}
