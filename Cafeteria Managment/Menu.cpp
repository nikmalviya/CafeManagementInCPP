class Menu
{
    UserData user;
public:
    Menu()
    {
        fstream file("ActiveUser.txt",ios::in|ios::out);
        file>>user;
        file.close();
    }
    void updateFile()
    {
        fstream file("ActiveUser.txt",ios::in|ios::out);
        file<<user;
        file.close();
    }
    void convertTempFile()
    {
        UserData usertemp;
        ofstream file;
        ifstream file1;
        file.open("UserData.txt");
        file1.open("temp.txt");
                    while(file1>>usertemp)
                    {
                        file<<usertemp;
                    }
        file.close();
        file1.close();
        remove("temp.txt");
    }
    void menu_layout();
    void menu_program();
    void my_account();
    void information();
    void edit_details();
    void view_details();
    void change_password();
    void log_out();
    void show_discount();
    void get_discount(int);
    void order_food();
    void view_recent_orders();
    void view_transactions();
    void clear_space()
    {
        Utility::setColor(0);
        Utility::setBackgroundColor(7);
        int x=21;
        for(int i=0;i<5;i++)
        {
            gotoxy(15,x);
            x++;
            for( int j=15;j<50;j++)
            {
                cout<<" ";
            }
        }
    }
};

