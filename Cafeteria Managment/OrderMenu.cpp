class OrderMenu
{
    UserData user;
public:
        string product_name;
        int quantity;
        int price;
    OrderMenu()
    {
        price=0;
        fstream file("ActiveUser.txt",ios::in|ios::out);
        file>>user;
        file.close();
    }
    void order_menu_layout();
    void order_menu_program();
    void product_catagory();
    void product(int);
    void fast_food();
    void ice_cream();
    void snacks();
    void cold_drinks();
    void clear_products();
    void getData(int,int,string);
    void pay_now();
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
};
class Order{
public:
    string name;
    string email;
    string product;
    int quantity;
    int price;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int srno;
    char suffix[6];
    friend fstream& operator << (fstream&,Order&);
    friend ofstream& operator << (ofstream&,Order&);
    friend fstream& operator>>(fstream&,Order&);
    friend ifstream& operator>>(ifstream&,Order&);
    Order()
    {
        Time time;
        day=time.getDate();
        month=time.getMonth();
        year=time.getYear();
        hour = time.getHour();
        minute = time.getMinute();
        char *su = time.getSuffix();
        strcpy(suffix,su);
    }
};
fstream& operator << (fstream& file, Order & order)
{
    file<<setiosflags(ios::left);
    file<<order.email<<space<<order.name<<space<<order.product<<space<<order.quantity<<space<<order.price<<space<<order.day<<space<<order.month<<space<<order.year<<space<<order.hour<<space<<order.minute<<space<<order.suffix<<space<<order.srno<<endl;
    return file;
}
ofstream& operator << (ofstream& fout, Order &order)
{
    fout<<setiosflags(ios::left);
    fout<<order.email<<space<<order.name<<space<<order.product<<space<<order.quantity<<space<<order.price<<space<<order.day<<space<<order.month<<space<<order.year<<space<<order.hour<<space<<order.minute<<space<<order.suffix<<space<<order.srno<<endl;
    return fout;
}
fstream& operator>>(fstream& file,Order & order)
{
    file>>order.email>>order.name>>order.product>>order.quantity>>order.price>>order.day>>order.month>>order.year>>order.hour>>order.minute>>order.suffix>>order.srno;
    return file;
}
ifstream& operator>>(ifstream& fin ,Order& order)
{
    fin>>order.email>>order.name>>order.product>>order.quantity>>order.price>>order.day>>order.month>>order.year>>order.hour>>order.minute>>order.suffix>>order.srno;
    return fin;
}
class Transaction{
public:
    string email;
    int day;
    int month;
    int year;
    int srno;
    int hour;
    int minute;
    int previous_balance;
    int amount;
    char suffix[6];
    int final_amt;
    friend ofstream& operator << (ofstream&,Transaction&);
    friend ifstream& operator>>(ifstream&,Transaction&);
    Transaction()
    {
        Time time;
        day=time.getDate();
        month=time.getMonth();
        year=time.getYear();
        hour=time.getHour();
        minute=time.getMinute();
        char *su = time.getSuffix();
        strcpy(suffix,su);
    }
};
ofstream& operator << (ofstream& fout, Transaction &order)
{
    fout<<order.email<<space<<order.day<<space<<order.month<<space<<order.year<<space<<order.hour<<space<<order.minute<<space<<order.suffix<<space<<order.previous_balance<<space<<order.amount<<space<<order.final_amt<<space<<order.srno<<endl;
    return fout;
}
ifstream& operator>>(ifstream& fin ,Transaction& order)
{
    fin>>order.email>>order.day>>order.month>>order.year>>order.hour>>order.minute>>order.suffix>>order.previous_balance>>order.amount>>order.final_amt>>order.srno;
    return fin;
}
